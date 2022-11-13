#include "REPCH.h"
#include "IndexBuffer.h"

#include "RandomEngine/Graphics/Renderer/RendererAPI.h"
#include "Platform/OpenGL/Buffers/OpenGLIndexBuffer.h"
#include "Platform/Vulkan/Buffers/VulkanIndexBuffer.h"

namespace RandomEngine::Graphics {

	IndexBuffer::IndexBuffer(unsigned int count)
		: Buffer(count) { }

	IndexBuffer::IndexBuffer(const Ref<unsigned int[]>& data, unsigned int count)
		: Buffer(data, count) { }

	IndexBufferRef IndexBuffer::Create(unsigned int count) {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLIndexBuffer>(count);
			case RendererAPI::API::Vulkan:
				return CreateRef<VulkanIndexBuffer>(count);
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

	IndexBufferRef IndexBuffer::Create(const Ref<unsigned int[]>& data, unsigned int count) {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLIndexBuffer>(data, count);
			case RendererAPI::API::Vulkan:
				return CreateRef<VulkanIndexBuffer>(data, count);
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

}
