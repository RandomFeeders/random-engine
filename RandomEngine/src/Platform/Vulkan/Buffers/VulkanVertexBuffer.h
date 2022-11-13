#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Buffers/VertexBuffer.h"

namespace RandomEngine::Graphics {

	class VulkanVertexBuffer : public VertexBuffer {

		private:


		public:
			VulkanVertexBuffer(unsigned int count);
			VulkanVertexBuffer(const Ref<float[]>& data, unsigned int count);
			virtual ~VulkanVertexBuffer();

			void Bind() const override;
			void Unbind() const override;

			void SetLayout(const BufferLayout& layout) override;
	};

}
