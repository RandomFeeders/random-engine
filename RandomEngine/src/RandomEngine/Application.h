#pragma once

#include "REPCH.h"

#include "Core.h"
#include "Window.h"

namespace RandomEngine {

	class RANDOM_ENGINE_API Application {
		
		private:
			bool _running = false;
			std::unique_ptr<Window> _window;

		public:
			Application();
			virtual ~Application();

			void Run();
	};

	Application* CreateApplication();

}