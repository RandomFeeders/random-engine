#include "REPCH.h"
#include "VertexBuffer.h"

#include "RandomEngine/Graphics/Renderer/RendererAPI.h"
#include "Platform/OpenGL/Buffers/OpenGLVertexBuffer.h"
#include "Platform/Vulkan/Buffers/VulkanVertexBuffer.h"

namespace RandomEngine::Graphics {

	VertexBuffer::VertexBuffer(unsigned int count)
		: Buffer(count) { }

	VertexBuffer::VertexBuffer(const Ref<float[]>& data, unsigned int count)
		: Buffer(data, count) { }

	void VertexBuffer::SetLayout(const BufferLayout& layout) {
		_layout = layout;
	}

	VertexBufferRef VertexBuffer::Create(unsigned int count) {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLVertexBuffer>(count);
			case RendererAPI::API::Vulkan:
				return CreateRef<VulkanVertexBuffer>(count);
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

	VertexBufferRef VertexBuffer::Create(const Ref<float[]>& data, unsigned int count) {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLVertexBuffer>(data, count);
			case RendererAPI::API::Vulkan:
				return CreateRef<VulkanVertexBuffer>(data, count);
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

}
