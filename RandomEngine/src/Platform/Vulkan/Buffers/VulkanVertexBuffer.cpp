#include "REPCH.h"
#include "VulkanVertexBuffer.h"

namespace RandomEngine::Graphics {

	VulkanVertexBuffer::VulkanVertexBuffer(float* data, unsigned int count)
		: VertexBuffer(data, count) {

	}

	VulkanVertexBuffer::~VulkanVertexBuffer() {

	}

	void VulkanVertexBuffer::Bind() const {

	}

	void VulkanVertexBuffer::Unbind() const {

	}

	void VulkanVertexBuffer::SetLayout(const BufferLayout& layout) {
		__super::SetLayout(layout);
	}

}
