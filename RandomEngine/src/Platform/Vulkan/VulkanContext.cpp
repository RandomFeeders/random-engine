#include "REPCH.h"
#include "VulkanContext.h"

#include <GLFW/glfw3.h>

namespace RandomEngine::Graphics {

	VulkanContext::VulkanContext(GLFWwindow* window)
		: _window(window) {
		RE_CORE_ASSERT(window, "Window handle cannot be null!");
	}

	void VulkanContext::Init() {
		glfwMakeContextCurrent(_window);

		// Add version check of vulkan
		// RE_CORE_INFO("OpenGL Info:");
		// RE_CORE_INFO("   Vendor: {0}", glGetString(GL_VENDOR));
		// RE_CORE_INFO("   Renderer: {0}", glGetString(GL_RENDERER));
		// RE_CORE_INFO("   Version: {0}", glGetString(GL_VERSION));
	}

	void VulkanContext::SwapBuffers() {
		glfwSwapBuffers(_window);
	}

}
