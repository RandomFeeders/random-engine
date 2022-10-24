#pragma once

#include "RandomEngine/Graphics/Context.h"

struct GLFWwindow;

namespace RandomEngine::Graphics {

	class OpenGLContext : public Context {

		private:
			GLFWwindow* _window;

		public:
			OpenGLContext(GLFWwindow* window);

			void Init() override;
			void SwapBuffers() override;

	};

}
