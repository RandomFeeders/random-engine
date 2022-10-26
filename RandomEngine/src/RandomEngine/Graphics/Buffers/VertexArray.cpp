#include "REPCH.h"
#include "VertexArray.h"

#include "RandomEngine/Graphics/Renderer.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexArray.h"
#include "Platform/Vulkan/Buffers/VulkanVertexArray.h"

namespace RandomEngine::Graphics {

	void VertexArray::AddVertexBuffer(const std::shared_ptr<VertexBuffer> buffer) {
		_vertexBuffers.push_back(buffer);
	}

	void VertexArray::SetIndexBuffer(const std::shared_ptr<IndexBuffer> buffer) {
		_indexBuffer = buffer;
	}

	VertexArray* VertexArray::Create() {
		switch (Renderer::GetAPI()) {
			case RendererAPI::OpenGL:
				return new OpenGLVertexArray();
			case RendererAPI::Vulkan:
				return new VulkanVertexArray();
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

}
