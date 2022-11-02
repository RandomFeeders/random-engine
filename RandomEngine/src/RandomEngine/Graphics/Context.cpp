#include "REPCH.h"
#include "Context.h"

#include "RandomEngine/Graphics/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include "Platform/Vulkan/VulkanContext.h"

namespace RandomEngine::Graphics {

	Context* Context::Create(GLFWwindow* window) {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return new OpenGLContext(window);
			case RendererAPI::API::Vulkan:
				return new VulkanContext(window);
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

}
