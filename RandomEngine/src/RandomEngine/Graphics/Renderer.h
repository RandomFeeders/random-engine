#pragma once

namespace RandomEngine::Graphics {

	enum class RendererAPI {
		None = 0,
		OpenGL = 1,
		Vulkan = 2
	};

	class Renderer {

		private:
			static RendererAPI _rendererAPI;

		public:
			static inline RendererAPI GetAPI() { return _rendererAPI; }
	};

}
