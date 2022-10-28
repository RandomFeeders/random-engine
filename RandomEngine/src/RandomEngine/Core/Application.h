#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Core/Window.h"
#include "RandomEngine/Core/LayerStack.h"
#include "RandomEngine/Core/Timestep.h"
#include "RandomEngine/Events/ApplicationEvent.h"
#include "RandomEngine/GUI/GuiLayer.h"

namespace RandomEngine {

	class Application {
		
		private:
			static Application* _instance;

			bool _running = false;
			Scope<Window> _window;
			LayerStack _layerStack;
			GuiLayer* _guiLayer;
			float _lastFrameTime;

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
