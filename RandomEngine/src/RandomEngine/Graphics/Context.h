#pragma once

#include "RandomEngine/Core/Types.h"

struct GLFWwindow;

namespace RandomEngine::Graphics {

	class Context {

		public:
			virtual void Init() = 0;
			virtual void SwapBuffers() = 0;

			static Scope<Context> Create(void* window);
	};

}
