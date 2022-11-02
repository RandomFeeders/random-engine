#pragma once

struct GLFWwindow;

namespace RandomEngine::Graphics {

	class Context {

		public:
			virtual void Init() = 0;
			virtual void SwapBuffers() = 0;

			static Context* Create(GLFWwindow* window);
	};

}
