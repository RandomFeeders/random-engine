#include "REPCH.h"

#include <GLFW/glfw3.h>

#include "Platform/Windows/WindowsWindow.h"
#include "RandomEngine/Graphics/Context.h"
#include "RandomEngine/Events/ApplicationEvent.h"
#include "RandomEngine/Events/KeyEvent.h"
#include "RandomEngine/Events/MouseEvent.h"
#include "RandomEngine/Graphics/Renderer/RendererAPI.h"

namespace RandomEngine {

	static unsigned int _glfwWindowCount = 0;

	static void GLFWErrorCallback(int code, const char* desc) {
		RE_CORE_ERROR("GLFW Error ({0}): {1}", code, desc);
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
		_data.Transparent = props.Transparent;
		_data.Minimized = false;

		RE_CORE_INFO("Creating window {0} ({1}, {2})", props.Title, props.Width, props.Height);

		if (_glfwWindowCount == 0) {
			RE_CORE_INFO("Initializing GLFW");

			int success = glfwInit();

			RE_CORE_ASSERT(success, "Cound not initialize GLFW!");

			glfwSetErrorCallback(GLFWErrorCallback);
		}

		glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, _data.Transparent ? GLFW_TRUE : GLFW_FALSE);

		#ifdef RE_ENV_DEBUG
		switch (Graphics::RendererAPI::GetAPI()) {
			case Graphics::RendererAPI::API::OpenGL:
				glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, GLFW_TRUE);
				break;
			case Graphics::RendererAPI::API::Vulkan:
				break;
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				break;
		}
		#endif

		_window = glfwCreateWindow(props.Width, props.Height, props.Title.c_str(), nullptr, nullptr);
		_glfwWindowCount++;

		_context = Graphics::Context::Create(_window);
		_context->Init();

		glfwSetWindowUserPointer(_window, &_data);
		SetVSync(true);

		SetEvents();
	}

	void WindowsWindow::SetEvents() {
		glfwSetWindowSizeCallback(_window, [](GLFWwindow* window, int width, int height)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				data.Width = width;
				data.Height = height;

				if (width == 0 || height == 0) {
					data.Minimized = true;
				} else {
					data.Minimized = false;
				}

				WindowResizeEvent event(width, height);
				data.EventCallback(event);
			});

		glfwSetWindowCloseCallback(_window, [](GLFWwindow* window)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				WindowCloseEvent event;
				data.EventCallback(event);
			});

		glfwSetKeyCallback(_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) {
					case GLFW_PRESS:
					{
						KeyPressedEvent event(static_cast<KeyCode>(key), 0);
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						KeyReleasedEvent event(static_cast<KeyCode>(key));
						data.EventCallback(event);
						break;
					}
					case GLFW_REPEAT:
					{
						KeyPressedEvent event(static_cast<KeyCode>(key), 1);
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetCharCallback(_window, [](GLFWwindow* window, unsigned int keycode)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				KeyTypedEvent event(static_cast<KeyCode>(keycode));
				data.EventCallback(event);
			});

		glfwSetMouseButtonCallback(_window, [](GLFWwindow* window, int button, int action, int mods)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);

				switch (action) {
					case GLFW_PRESS:
					{
						MouseButtonPressedEvent event(static_cast<MouseCode>(button));
						data.EventCallback(event);
						break;
					}
					case GLFW_RELEASE:
					{
						MouseButtonReleasedEvent event(static_cast<MouseCode>(button));
						data.EventCallback(event);
						break;
					}
				}
			});

		glfwSetScrollCallback(_window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseScrolledEvent event((float)xOffset, (float)yOffset);
				data.EventCallback(event);
			});

		glfwSetCursorPosCallback(_window, [](GLFWwindow* window, double xPos, double yPos)
			{
				WindowData& data = *(WindowData*)glfwGetWindowUserPointer(window);
				MouseMovedEvent event((float)xPos, (float)yPos);
				data.EventCallback(event);
			});
	}

	void WindowsWindow::Shutdown() {
		if (_window != nullptr) glfwDestroyWindow(_window);

		if (--_glfwWindowCount == 0) {
			RE_CORE_INFO("No more windows is present, terminating GLFW");
			glfwTerminate();
		}
	}

	void WindowsWindow::OnUpdate() {
		glfwPollEvents();
		_context->SwapBuffers();
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
