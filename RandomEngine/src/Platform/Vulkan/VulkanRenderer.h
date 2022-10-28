#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Renderer/RendererAPI.h"

namespace RandomEngine::Graphics {

	class VulkanRenderer : public RendererAPI {

	public:
		void Clear() override;
		void SetClearColor(const Maths::Vector4f& color) override;

		void DrawIndexed(const VertexArrayRef& vertexArray) override;
	};

}
