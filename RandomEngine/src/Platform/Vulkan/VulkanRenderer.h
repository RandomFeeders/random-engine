#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Renderer/RendererAPI.h"

namespace RandomEngine::Graphics {

	class VulkanRenderer : public RendererAPI {

	public:
		void Init() override;
		void Shutdown() override;

		void Clear() override;
		void SetClearColor(const Maths::Vector4f& color) override;
		void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) override;

		void DrawIndexed(const VertexArrayRef& vertexArray, unsigned int indexCount = 0) override;
	};

}
