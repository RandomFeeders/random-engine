#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Buffers/VertexArray.h"

namespace RandomEngine::Graphics {

	class VulkanVertexArray : public VertexArray {

		public:
			VulkanVertexArray();
			virtual ~VulkanVertexArray();

			void Bind() const override;
			void Unbind() const override;

			void AddVertexBuffer(const VertexBufferRef buffer) override;
			void SetIndexBuffer(const IndexBufferRef buffer) override;
	};

}
