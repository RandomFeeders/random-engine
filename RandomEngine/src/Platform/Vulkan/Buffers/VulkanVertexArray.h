#pragma once

#include "RandomEngine/Graphics/Buffers/VertexArray.h"

namespace RandomEngine::Graphics {

	class VulkanVertexArray : public VertexArray {

		public:
			VulkanVertexArray();
			virtual ~VulkanVertexArray();

			void Bind() const override;
			void Unbind() const override;

			void AddVertexBuffer(const std::shared_ptr<VertexBuffer> buffer) override;
			void SetIndexBuffer(const std::shared_ptr<IndexBuffer> buffer) override;
	};

}
