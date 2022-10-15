#pragma once

#include "REPCH.h"

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace RandomEngine {

	class Application {
		
		private:
			static Application* _instance;

			bool _running = false;
			std::unique_ptr<Window> _window;
			LayerStack _layerStack;

			bool OnWindowClose(WindowCloseEvent& e);

		public:
			Application();
			virtual ~Application();

			void Run();
			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);

			inline Window& GetWindow() const { return *_window; }

			inline static Application& GetInstance() { return *_instance; }
	};

	Application* CreateApplication();

}