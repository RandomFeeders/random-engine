#pragma once

#include "RandomEngine/Graphics/Renderer/RendererAPI.h"

namespace RandomEngine::Graphics {

	class OpenGLRenderer : public RendererAPI {

		public:
			void Clear() override;
			void SetClearColor(const Maths::Vector4f& color) override;

			void DrawIndexed(const VertexArrayRef& vertexArray) override;
	};

}
