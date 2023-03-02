#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Core/Window.h"
#include "RandomEngine/Core/LayerStack.h"
#include "RandomEngine/Core/Timestep.h"
#include "RandomEngine/Events/ApplicationEvent.h"
#include "RandomEngine/GUI/GuiLayer.h"

int main(int argc, char** argv);

namespace RandomEngine {

	struct ApplicationProps {

		public:
			String Title;
			uint Width;
			uint Height;
			bool TransparentWindow;

			ApplicationProps(const String& title = "Random Engine", uint width = 1280, uint height = 720, bool transparentWindow = false)
				: Title(title), Width(width), Height(height), TransparentWindow(transparentWindow) { }
	};

	class Application {
		
		private:
			static Application* _instance;
			friend int ::main(int argc, char** argv);

			bool _running = false;
			bool _minimized = false;
			bool _runOnBackground = false;
			Scope<Window> _window;
			LayerStack _layerStack;
			GuiLayer* _guiLayer;
			float _lastFrameTime;

			bool OnWindowResized(WindowResizeEvent& e);
			bool OnWindowClose(WindowCloseEvent& e);

			void Run();

		public:
			Application(const ApplicationProps& props = ApplicationProps());
			virtual ~Application();

			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);

			inline Window& GetWindow() const { return *_window; }

			inline static Application& GetInstance() { return *_instance; }
	};

	Application* CreateApplication();

}
