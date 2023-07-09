#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Events/Event.h"
#include "RandomEngine/Core/WindowMode.h"

namespace RandomEngine {

	struct WindowProps {

		public:
			String Title;
			uint Width;
			uint Height;
			WindowMode Mode;
			int MonitorIndex;
			bool Transparent;
			bool Border;

			WindowProps(
				const String& title = "Random Engine",
				uint width = 1280,
				uint height = 720,
				WindowMode mode = WindowMode::Windowed,
				int monitorIndex = 0,
				bool transparent = false,
				bool border = true) 
				  : Title(title), 
				    Width(width), 
				    Height(height),
					Mode(mode),
					MonitorIndex(monitorIndex),
				    Transparent(transparent), 
				    Border(border) { }
	};

	class Window {

		public:

			using EventCallbackFn = Func<void(Event&)>;

			virtual ~Window() { }

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual void SetMonitor(int index) = 0;
			virtual void SetMode(WindowMode mode) = 0;
			virtual WindowMode GetMode() const = 0;
			virtual bool IsVSync() const = 0;
			virtual bool IsMinimized() const = 0;

			virtual void* GetNativeWindow() const = 0;

			static Scope<Window> Create(const WindowProps& props = WindowProps());
	};

}
