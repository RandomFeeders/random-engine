#pragma once

#include "RandomEngine/Maths/Maths.h"
#include "RandomEngine/Graphics/Buffers/VertexArray.h"

namespace RandomEngine::Graphics {

	class RenderCommands {

		public:
			static void Clear();
			static void SetClearColor(const Maths::Vector4f& color);

			static void DrawIndexed(const VertexArrayRef& vertexArray);
	};

}
