#include "REPCH.h"
#include "application.h"

#include <GLFW/glfw3.h>

#include "RandomEngine/Graphics/Renderer/Renderer.h"
#include "RandomEngine/Graphics/Renderer/RenderCommands.h"
#include "RandomEngine/Graphics/Buffers/BufferLayout.h"
#include "RandomEngine/Graphics/Buffers/VertexBuffer.h"
#include "RandomEngine/Graphics/Buffers/IndexBuffer.h"

namespace RandomEngine {

	Application* Application::_instance = nullptr;

	Application::Application() {
		RE_CORE_ASSERT(!_instance, "Application already exists!");
		_instance = this;

		_window = Window::Create();
		_window->SetEventCallback(RE_BIND_EVENT_FN(Application::OnEvent));

		Graphics::Renderer::Init();

		_guiLayer = new GuiLayer();
		PushOverlay(_guiLayer);
	}

	Application::~Application() { 
		Graphics::Renderer::Shutdown();
	}

	void Application::Run() {
		_running = true;

		while (_running) {
			float time = (float)glfwGetTime();
			Timestep timestep = time - _lastFrameTime;
			_lastFrameTime = time;

			if (!_window->IsMinimized() || _runOnBackground) {
				for (Layer* layer : _layerStack) {
					layer->OnUpdate({ timestep });
				}
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
		dispatcher.Dispatch<WindowResizeEvent>(RE_BIND_EVENT_FN(Application::OnWindowResized));
		dispatcher.Dispatch<WindowCloseEvent>(RE_BIND_EVENT_FN(Application::OnWindowClose));

		for (auto iterator = _layerStack.end(); iterator != _layerStack.begin(); ) {
			(*--iterator)->OnEvent(e);
			if (e.IsHandled()) {
				break;
			}
		}
	}

	bool Application::OnWindowResized(WindowResizeEvent& e) {
		if (e.IsMinimized()) return false;

		Graphics::Renderer::OnWindowResized(e.GetWidth(), e.GetHeight());

		return false;
	}

	bool Application::OnWindowClose(WindowCloseEvent& e) {
		_running = false;
		return true;
	}

	void Application::PushLayer(Layer* layer) {
		_layerStack.PushLayer(layer);
	}

	void Application::PushOverlay(Layer* overlay) {
		_layerStack.PushOverlay(overlay);
	}

}
