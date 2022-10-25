#include "REPCH.h"

#include "VulkanIndexBuffer.h"

namespace RandomEngine::Graphics {

	VulkanIndexBuffer::VulkanIndexBuffer(unsigned int* data, unsigned int count)
		: IndexBuffer(data, count) {

	}

	VulkanIndexBuffer::~VulkanIndexBuffer() {

	}

	void VulkanIndexBuffer::Bind() const {

	}

	void VulkanIndexBuffer::Unbind() const {

	}

}
