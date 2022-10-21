#pragma once

#include "RandomEngine/Core/Window.h"

namespace RandomEngine {

	class WindowsWindow : public Window {

		private:
			struct WindowData {
				std::string Title;
				unsigned int Width;
				unsigned int Height;
				bool VSync;

				EventCallbackFn EventCallback;
			};

			GLFWwindow* _window;
			WindowData _data;
			

			virtual void Init(const WindowProps& props);
			virtual void SetEvents();
			virtual void Shutdown();

		public:
			WindowsWindow(const WindowProps& props);
			virtual ~WindowsWindow();

			void OnUpdate() override;

			inline unsigned int GetWidth() const override { return _data.Width; }
			inline unsigned int GetHeight() const override { return _data.Height; }

			inline void SetEventCallback(const EventCallbackFn& callback) override { _data.EventCallback = callback; }
			void SetVSync(bool enabled) override;
			inline bool IsVSync() const override { return _data.VSync; }

			inline void* GetNativeWindow() const override { return _window; }
	};

}