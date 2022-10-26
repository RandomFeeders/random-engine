#include "REPCH.h"

#include <glad/glad.h>

#include "application.h"
#include "RandomEngine/Graphics/Buffers/BufferLayout.h"

namespace RandomEngine {

	Application* Application::_instance = nullptr;

	Application::Application() {
		RE_CORE_ASSERT(!_instance, "Application already exists!");
		_instance = this;

		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		_guiLayer = new GuiLayer();
		PushOverlay(_guiLayer);

		glGenVertexArrays(1, &_vertexArray);
		glBindVertexArray(_vertexArray);

		float vertices[3 * 7] = {
			-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
			0.5f, -0.5f, 0.0f, 0.2f, 0.8f, 0.8f, 1.0f,
			0.0f, 0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};

		_vertexBuffer.reset(Graphics::VertexBuffer::Create(vertices, 3 * 7));

		Graphics::BufferLayout layout = {
			{ "_position", ShaderDataType::Vector3f },
			{ "_color", ShaderDataType::Vector4f }
		};

		// _vertexBuffer->SetLayout(layout);

		unsigned int index = 0;
		for (auto& element : layout) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(index, element.ComponentCount, 
				GL_FLOAT, GL_FALSE, layout.GetStride(), (const void*) element.Offset);
			index++;
		}

		

		unsigned int indices[3 * 1] = { 0, 1, 2 };

		_indexBuffer.reset(Graphics::IndexBuffer::Create(indices, 3));
		_indexBuffer->Bind();

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec4 _position;
			layout(location = 1) in vec4 _color;

			out vec4 v_position;
			out vec4 v_color;

			void main() {
				v_position = _position;
				gl_Position = _position;
				v_color = _color;
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec4 v_position;
			in vec4 v_color;

			void main() {
				color = vec4(v_position * 0.5 + 0.5);
				color = v_color;
			}
		)";

		_shader.reset(new Graphics::Shader(vertexSrc, fragmentSrc));
	}

	Application::~Application() { }

	void Application::Run() {
		_running = true;

		while (_running) {
			glClearColor(0.1f, 0.1f, 0.1f, 1);
			glClear(GL_COLOR_BUFFER_BIT);

			_shader->Bind();
			glBindVertexArray(_vertexArray);
			glDrawElements(GL_TRIANGLES, _indexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

			for (Layer* layer : _layerStack) {
				layer->OnUpdate();
			}

			_guiLayer->Begin();
			for (Layer* layer : _layerStack) {
				layer->OnGUIRender();
			}
			_guiLayer->End();

			_window->OnUpdate();
		}
	}

	void Application::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(Application::OnWindowClose));

		for (auto iterator = _layerStack.end(); iterator != _layerStack.begin(); ) {
			(*--iterator)->OnEvent(e);
			if (e.IsHandled()) {
				break;
			}
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		_running = false;
		return true;
	}

	void Application::PushLayer(Layer* layer) {
		_layerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* overlay) {
		_layerStack.PushOverlay(overlay);
		overlay->OnAttach();
	}

}
