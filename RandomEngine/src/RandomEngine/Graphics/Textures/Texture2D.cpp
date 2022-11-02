#include "REPCH.h"
#include "Texture2D.h"

#include "RandomEngine/Graphics/Renderer/RendererAPI.h"
#include "Platform/OpenGL/Textures/OpenGLTexture2D.h"
#include "Platform/Vulkan/Textures/VulkanTexture2D.h"

namespace RandomEngine::Graphics {

	Texture2D::Texture2D(const String& path)
		: Texture(path) { }

	Texture2D::Texture2D(unsigned int width, unsigned int height) 
		: Texture(width, height) { }

	Texture2DRef Texture2D::Create(const String& path) {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLTexture2D>(path);
			case RendererAPI::API::Vulkan:
				return CreateRef<VulkanTexture2D>(path);
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

	Texture2DRef Texture2D::Create(unsigned int width, unsigned int height) {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return CreateRef<OpenGLTexture2D>(width, height);
			case RendererAPI::API::Vulkan:
				return CreateRef<VulkanTexture2D>(width, height);
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

}
