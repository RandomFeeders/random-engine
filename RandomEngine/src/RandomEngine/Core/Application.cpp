#include "REPCH.h"

#include <glad/glad.h>

#include "application.h"
#include "RandomEngine/Graphics/Buffers/BufferLayout.h"
#include "RandomEngine/Graphics/Buffers/VertexBuffer.h"
#include "RandomEngine/Graphics/Buffers/IndexBuffer.h"

namespace RandomEngine {

	Application* Application::_instance = nullptr;

	Application::Application() {
		RE_CORE_ASSERT(!_instance, "Application already exists!");
		_instance = this;

		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		_guiLayer = new GuiLayer();
		PushOverlay(_guiLayer);

		_vertexArray.reset(Graphics::VertexArray::Create());

		float vertices[7 * 7] = {
			-0.45f, -0.50f, 0.00f, 0.8f, 0.8, 0.2f, 1.0f,	// A - 0
			 0.00f, -0.75f, 0.00f, 0.8f, 0.2, 0.8f, 1.0f,	// B - 1
			 0.00f,  0.00f, 0.00f, 0.2f, 0.8, 0.8f, 1.0f,	// C - 2
			-0.45f,  0.50f, 0.00f, 0.2f, 0.2, 0.8f, 1.0f,	// D - 3
			 0.45f, -0.50f, 0.00f, 0.2f, 0.8, 0.2f, 1.0f,	// E - 4
			 0.45f,  0.50f, 0.00f, 0.8f, 0.2, 0.2f, 1.0f,	// F - 5
			 0.00f,  0.75f, 0.00f, 0.8f, 0.2, 0.8f, 1.0f	// G - 6
		};

		std::shared_ptr<Graphics::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Graphics::VertexBuffer::Create(vertices, 7 * 7));

		Graphics::BufferLayout layout = {
			{ "_position", ShaderDataType::Vector3f },
			{ "_color", ShaderDataType::Vector4f }
		};

		vertexBuffer->SetLayout(layout);

		unsigned int indices[3 * 6] = { 
			0, 1, 2, 
			2, 3, 0, 
			1, 4, 5, 
			5, 2, 1, 
			3, 2, 5, 
			5, 6, 3
		};

		std::shared_ptr<Graphics::IndexBuffer> indexBuffer;
		indexBuffer.reset(Graphics::IndexBuffer::Create(indices, 3 * 6));

		_vertexArray->AddVertexBuffer(vertexBuffer);
		_vertexArray->SetIndexBuffer(indexBuffer);
		_vertexArray->Bind();

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
			_vertexArray->Bind();
			glDrawElements(GL_TRIANGLES, _vertexArray->GetIndexBuffer()->GetCount(), GL_UNSIGNED_INT, nullptr);

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
