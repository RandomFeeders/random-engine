#include "REPCH.h"

#include <GLFW/glfw3.h>

#include "RandomEngine/Core/Application.h"

#ifdef RE_PLATFORM_WINDOWS

namespace RandomEngine {

	Scope<Monitor[]> Application::GetMonitors(int* count) {
		auto glfwMonitors = glfwGetMonitors(count);
		auto monitorList = CreateScope<Monitor[]>(*count);

		for (int i = 0; i < *count; i++) {
			auto mode = glfwGetVideoMode(glfwMonitors[i]);
			String name = glfwGetMonitorName(glfwMonitors[i]);

			monitorList[i] = Monitor(
				i,
				name,
				mode->width,
				mode->height
			);
		}

		return monitorList;
	}

}

#endif
