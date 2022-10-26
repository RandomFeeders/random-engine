#pragma once

#include "RandomEngine/Graphics/Buffers/VertexBuffer.h"

namespace RandomEngine::Graphics {

	class VulkanVertexBuffer : public VertexBuffer {

		private:


		public:
			VulkanVertexBuffer(float* data, unsigned int count);
			virtual ~VulkanVertexBuffer();

			void Bind() const override;
			void Unbind() const override;

			void SetLayout(const BufferLayout& layout) override;
	};

}
