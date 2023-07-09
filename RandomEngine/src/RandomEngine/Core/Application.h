#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Core/Window.h"
#include "RandomEngine/Core/LayerStack.h"
#include "RandomEngine/Core/Timestep.h"
#include "RandomEngine/Events/ApplicationEvent.h"
#include "RandomEngine/GUI/GuiLayer.h"
#include "RandomEngine/Core/WindowMode.h"

int main(int argc, char** argv);

namespace RandomEngine {

	struct ApplicationProps {

		public:
			String Title;
			uint Width;
			uint Height;
			bool TransparentWindow;
			bool BorderWindow;
			WindowMode WindowMode;
			int MonitorIndex;

			ApplicationProps(
				const String& title = "Random Engine", 
				uint width = 1280, 
				uint height = 720,
				RandomEngine::WindowMode windowMode = WindowMode::Windowed,
				int monitorIndex = 0,
				bool transparentWindow = false,
				bool borderWindow = true
			) : Title(title), 
				Width(width), 
				Height(height), 
				WindowMode(windowMode),
				MonitorIndex(monitorIndex),
				TransparentWindow(transparentWindow), 
				BorderWindow(borderWindow) { }
	};

	struct Monitor {

		public:
			int Index;
			String Name;
			uint Width;
			uint Height;

		Monitor() { }
		Monitor(
			int index,
			String name,
			uint width,
			uint height
		) : Index(index),
			Name(name),
			Width(width),
			Height(height) { }
	};

	class Application {
		
		private:
			static Application* _instance;
			friend int ::main(int argc, char** argv);

			bool _running = false;
			bool _minimized = false;
			bool _runOnBackground = false;
			Scope<Window> _window;
			int _monitorCount;
			int _monitorIndex;
			Scope<Monitor[]> _monitorList;
			LayerStack _layerStack;
			GuiLayer* _guiLayer;
			float _lastFrameTime;

			bool OnWindowResized(WindowResizeEvent& e);
			bool OnWindowClose(WindowCloseEvent& e);

			void Run();

			static Scope<Monitor[]> GetMonitors(int* count);

		public:
			Application(const ApplicationProps& props = ApplicationProps());
			virtual ~Application();

			void Close();

			void OnEvent(Event& e);

			void PushLayer(Layer* layer);
			void PushOverlay(Layer* overlay);

			inline Window& GetWindow() const { return *_window; }
			inline int GetMonitorCount() const { return _monitorCount; }
			inline const Monitor& GetMonitor(int index) const { 
				RE_CORE_ASSERT(index < 0 || index >= _monitorCount, "Monitor index out of range");
				return _monitorList[index];
			}
			inline const Monitor& GetCurrentMonitor() { return _monitorList[_monitorIndex]; }

			inline static Application& GetInstance() { return *_instance; }
	};

	Application* CreateApplication();


}
