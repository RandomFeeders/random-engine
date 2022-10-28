#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Events/Event.h"

namespace RandomEngine {

	struct WindowProps {

		public:
			String Title;
			unsigned int Width;
			unsigned int Height;

			WindowProps(
				const String& title = "Random Engine",
				unsigned int width = 1280,
				unsigned int height = 720) 
				: Title(title), Width(width), Height(height) { }
	};

	class Window {

		public:
			using EventCallbackFn = std::function<void(Event&)>;

			virtual ~Window() { }

			virtual void OnUpdate() = 0;

			virtual unsigned int GetWidth() const = 0;
			virtual unsigned int GetHeight() const = 0;

			virtual void SetEventCallback(const EventCallbackFn& callback) = 0;
			virtual void SetVSync(bool enabled) = 0;
			virtual bool IsVSync() const = 0;

			virtual void* GetNativeWindow() const = 0;

			static Window* Create(const WindowProps& props = WindowProps());
	};

}
