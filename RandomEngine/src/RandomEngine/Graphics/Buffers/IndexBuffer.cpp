#include "REPCH.h"
#include "IndexBuffer.h"

#include "RandomEngine/Graphics/Renderer/RendererAPI.h"
#include "Platform/OpenGL/Buffers/OpenGLIndexBuffer.h"
#include "Platform/Vulkan/Buffers/VulkanIndexBuffer.h"

namespace RandomEngine::Graphics {

	IndexBuffer::IndexBuffer(unsigned int* data, unsigned int count)
		: Buffer(data, count) { }

	IndexBufferRef IndexBuffer::Create(unsigned int* data, unsigned int count) {
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
