#include "REPCH.h"

#include <glad/glad.h>

#include "application.h"

namespace RandomEngine {

	Application* Application::_instance = nullptr;

	Application::Application() {
		RE_CORE_ASSERT(!_instance, "Application already exists!");
		_instance = this;

		_window = std::unique_ptr<Window>(Window::Create());
		_window->SetEventCallback(BIND_EVENT_FN(Application::OnEvent));

		_guiLayer = new GuiLayer();
		PushOverlay(_guiLayer);
	}

	Application::~Application() { }

	void Application::Run() {
		_running = true;

		while (_running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);

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