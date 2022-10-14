#include "REPCH.h"

#include "WindowsWindow.h"

namespace RandomEngine {

	static bool _glfwInitialized = false;

	Window* Window::Create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		Init(props);
	}

	WindowsWindow::~WindowsWindow() {
		Shutdown();
	}

	void WindowsWindow::Init(const WindowProps& props) {
		_data.Title = props.Title;
		_data.Width = props.Width;
		_data.Height = props.Height;

		RE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (!_glfwInitialized) {
			int success = glfwInit();

			RE_CORE_ASSERT(success, "Cound not initialize GLFW!");

			_glfwInitialized = true;
		}

		_window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(_window);
		glfwSetWindowUserPointer(_window, &_data);
		SetVSync(true);
	}

	void WindowsWindow::Shutdown() {
		glfwDestroyWindow(_window);
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(_window);
	}

	void WindowsWindow::SetVSync(bool enabled) {
		if (enabled) {
			glfwSwapInterval(1);
		}
		else {
			glfwSwapInterval(0);
		}

		_data.VSync = enabled;
	}

}