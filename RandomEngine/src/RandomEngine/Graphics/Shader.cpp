#include "REPCH.h"
#include "Shader.h"

#include "RandomEngine/Graphics/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "Platform/Vulkan/VulkanShader.h"

namespace RandomEngine::Graphics {

	ShaderRef Shader::Create(const String& vertexSrc, const String& fragmentSrc) {
		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				return ShaderRef(new OpenGLShader(vertexSrc, fragmentSrc));
			case RendererAPI::API::Vulkan:
				return ShaderRef(new VulkanShader(vertexSrc, fragmentSrc));
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}
	}

}
