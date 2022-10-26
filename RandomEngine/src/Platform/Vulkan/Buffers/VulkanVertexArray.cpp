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

	void VulkanVertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> buffer) { 
		__super::AddVertexBuffer(buffer);
	}

	void VulkanVertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> buffer) { 
		__super::SetIndexBuffer(buffer);
	}

}
