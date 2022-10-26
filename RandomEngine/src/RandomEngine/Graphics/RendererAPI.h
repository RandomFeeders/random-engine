#pragma once

#include <memory>
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
			virtual void Clear() = 0;
			virtual void SetClearColor(const Maths::Vector4f& color) = 0;

			virtual void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray) = 0;

			static inline API GetAPI() { return _rendererAPI; }
	};

}
