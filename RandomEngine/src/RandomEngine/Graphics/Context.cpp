#include "REPCH.h"
#include "Context.h"

#include "RandomEngine/Graphics/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLContext.h"
#include "Platform/Vulkan/VulkanContext.h"

namespace RandomEngine::Graphics {

	Scope<Context> Context::Create(void* window) {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return CreateScope<OpenGLContext>(static_cast<GLFWwindow*>(window));
			case RendererAPI::API::Vulkan:
				return CreateScope<VulkanContext>(static_cast<GLFWwindow*>(window));
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

}
