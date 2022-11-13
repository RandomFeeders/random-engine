#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Buffers/IndexBuffer.h"

namespace RandomEngine::Graphics {

	class VulkanIndexBuffer : public IndexBuffer {

		private:


		public:
			VulkanIndexBuffer(unsigned int count);
			VulkanIndexBuffer(const Ref<unsigned int[]>& data, unsigned int count);
			virtual ~VulkanIndexBuffer();

			void Bind() const override;
			void Unbind() const override;
	};

}
