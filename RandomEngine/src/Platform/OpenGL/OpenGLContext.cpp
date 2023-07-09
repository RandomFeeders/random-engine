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
		RE_CORE_INFO("   Vendor: {0}", reinterpret_cast<const char*>(glGetString(GL_VENDOR)));
		RE_CORE_INFO("   Renderer: {0}", reinterpret_cast<const char*>(glGetString(GL_RENDERER)));
		RE_CORE_INFO("   Version: {0}", reinterpret_cast<const char*>(glGetString(GL_VERSION)));

		#ifdef RE_ENABLE_ASSERTS
			int versionMajor, versionMinor;
			glGetIntegerv(GL_MAJOR_VERSION, &versionMajor);
			glGetIntegerv(GL_MINOR_VERSION, &versionMinor);

			RE_CORE_ASSERT(versionMajor > 4 || (versionMajor == 4 && versionMinor >= 5), "Random Engine requires at least OpenGL version 4.5!");
		#endif
	}

	void OpenGLContext::SwapBuffers() {
		glfwSwapBuffers(_window);
	}

}
