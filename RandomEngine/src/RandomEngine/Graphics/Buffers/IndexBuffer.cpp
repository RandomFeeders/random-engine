#include "REPCH.h"

#include "IndexBuffer.h"

#include "RandomEngine/Graphics/RendererAPI.h"
#include "Platform/OpenGL/Buffers/OpenGLIndexBuffer.h"
#include "Platform/Vulkan/Buffers/VulkanIndexBuffer.h"

namespace RandomEngine::Graphics {

	IndexBuffer::IndexBuffer(unsigned int* data, unsigned int count)
		: Buffer<unsigned int>(data, count) { }

	IndexBuffer* IndexBuffer::Create(unsigned int* data, unsigned int count) {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return new OpenGLIndexBuffer(data, count);
			case RendererAPI::API::Vulkan:
				return new VulkanIndexBuffer(data, count);
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

}
