#include "REPCH.h"
#include "application.h"

#include <GLFW/glfw3.h>

#include "RandomEngine/Graphics/Renderer.h"
#include "RandomEngine/Graphics/RenderCommands.h"
#include "RandomEngine/Graphics/Buffers/BufferLayout.h"
#include "RandomEngine/Graphics/Buffers/VertexBuffer.h"
#include "RandomEngine/Graphics/Buffers/IndexBuffer.h"

namespace RandomEngine {

	Application* Application::_instance = nullptr;

	Application::Application() {
		RE_CORE_ASSERT(!_instance, "Application already exists!");
		_instance = this;

		Graphics::Renderer::Init();

		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		_guiLayer = new GuiLayer();
		PushOverlay(_guiLayer);
	}

	Application::~Application() { }

	void Application::Run() {
		_running = true;

		while (_running) {
			float time = (float)glfwGetTime();
			Timestep timestep = time - _lastFrameTime;
			_lastFrameTime = time;

			for (Layer* layer : _layerStack) {
				layer->OnUpdate(timestep);
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
