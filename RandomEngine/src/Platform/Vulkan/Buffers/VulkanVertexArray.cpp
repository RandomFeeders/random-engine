#include "REPCH.h"
#include "VulkanVertexArray.h"

namespace RandomEngine::Graphics {

	VulkanVertexArray::VulkanVertexArray() { 

	}

	VulkanVertexArray::~VulkanVertexArray() { 

	}

	void VulkanVertexArray::Bind() const { 

	}

	void VulkanVertexArray::Unbind() const { 

	}

	void VulkanVertexArray::AddVertexBuffer(const VertexBufferRef buffer) {
		__super::AddVertexBuffer(buffer);
	}

	void VulkanVertexArray::SetIndexBuffer(const IndexBufferRef buffer) {
		__super::SetIndexBuffer(buffer);
	}

}
