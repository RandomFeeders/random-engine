#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Maths/Maths.h"
#include "RandomEngine/Graphics/Buffers/VertexArray.h"

namespace RandomEngine::Graphics {

	class RendererAPI {

		public:
			enum class API {
				None = 0,
				OpenGL = 1,
				Vulkan = 2
			};

		private:
			static API _rendererAPI;

		public:
			virtual void Init() = 0;
			virtual void Shutdown() = 0;

			virtual void Clear() = 0;
			virtual void SetClearColor(const Maths::Vector4f& color) = 0;
			virtual void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) = 0;

			virtual void DrawIndexed(const VertexArrayRef& vertexArray) = 0;

			static inline API GetAPI() { return _rendererAPI; }
	};

}
