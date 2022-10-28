#include "REPCH.h"
#include "OpenGLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace RandomEngine::Graphics {

	OpenGLContext::OpenGLContext(GLFWwindow* window)
		: _window(window) { 
		RE_CORE_ASSERT(window, "Window handle cannot be null!");
	}

	void OpenGLContext::Init() {
		glfwMakeContextCurrent(_window);

		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		RE_CORE_ASSERT(status, "Failed to initialize GLAD!");

		RE_CORE_INFO("OpenGL Info:");
		RE_CORE_INFO("   Vendor: {0}", glGetString(GL_VENDOR));
		RE_CORE_INFO("   Renderer: {0}", glGetString(GL_RENDERER));
		RE_CORE_INFO("   Version: {0}", glGetString(GL_VERSION));
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(_window);
	}

}
