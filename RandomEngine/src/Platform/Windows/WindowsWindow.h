#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Core/Window.h"
#include "RandomEngine/Graphics/Context.h"

namespace RandomEngine {

	class WindowsWindow : public Window {

		private:
			struct WindowData {
				String Title;
				unsigned int Width = 0;
				unsigned int Height = 0;
				bool VSync = false;
				bool Minimized = false;
				bool Transparent = false;
				bool Border = true;

				EventCallbackFn EventCallback;
			};

			GLFWwindow* _window;
			Scope<Graphics::Context> _context;
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
			inline bool IsMinimized() const override { return _data.Minimized; }

			inline void* GetNativeWindow() const override { return _window; }
	};

}
