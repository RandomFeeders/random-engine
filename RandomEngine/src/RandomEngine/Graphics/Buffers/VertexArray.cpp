#include "REPCH.h"
#include "VertexArray.h"

#include "RandomEngine/Graphics/Renderer/RendererAPI.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexArray.h"
#include "Platform/Vulkan/Buffers/VulkanVertexArray.h"

namespace RandomEngine::Graphics {

	void VertexArray::AddVertexBuffer(const VertexBufferRef buffer) {
		_vertexBuffers.push_back(buffer);
	}

	void VertexArray::SetIndexBuffer(const IndexBufferRef buffer) {
		_indexBuffer = buffer;
	}

	VertexArrayRef VertexArray::Create() {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return VertexArrayRef(new OpenGLVertexArray());
			case RendererAPI::API::Vulkan:
				return VertexArrayRef(new VulkanVertexArray());
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

}
