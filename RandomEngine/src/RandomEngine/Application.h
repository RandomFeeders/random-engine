#pragma once

#include "REPCH.h"

#include "Core.h"
#include "Window.h"
#include "Events/ApplicationEvent.h"

namespace RandomEngine {

	class RANDOM_ENGINE_API Application {
		
		private:
			bool _running = false;
			std::unique_ptr<Window> _window;

			bool OnWindowClose(WindowCloseEvent& e);

		public:
			Application();
			virtual ~Application();

			void Run();
			void OnEvent(Event& e);
	};

	Application* CreateApplication();

}