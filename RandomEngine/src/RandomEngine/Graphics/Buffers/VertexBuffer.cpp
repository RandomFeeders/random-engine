#include "REPCH.h"

#include "VertexBuffer.h"

#include "RandomEngine/Graphics/Renderer.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexBuffer.h"
#include "Platform/Vulkan/Buffers/VulkanVertexBuffer.h"

namespace RandomEngine::Graphics {

	VertexBuffer::VertexBuffer(float* data, unsigned int count)
		: Buffer(data, count), _layout(BufferLayout::Default()) { }

	void VertexBuffer::SetLayout(const BufferLayout& layout) {
		_layout = layout;
	}

	VertexBuffer* VertexBuffer::Create(float* data, unsigned int count) {
		switch (Renderer::GetAPI()) {
			case RendererAPI::OpenGL:
				return new OpenGLVertexBuffer(data, count);
			case RendererAPI::Vulkan:
				return new VulkanVertexBuffer(data, count);
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

	BufferLayout& BufferLayout::Default() {
		BufferLayout layout = { };
		return layout;
	}

}
