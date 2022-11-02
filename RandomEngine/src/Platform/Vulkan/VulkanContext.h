#pragma once

#include "RandomEngine/Graphics/Context.h"

struct GLFWwindow;

namespace RandomEngine::Graphics {

	class VulkanContext : public Context {

		private:
			GLFWwindow* _window;

		public:
			VulkanContext(GLFWwindow* window);

			void Init() override;
			void SwapBuffers() override;

	};

}
