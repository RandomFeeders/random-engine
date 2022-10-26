#include "REPCH.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLRenderer.h"
#include "Platform/Vulkan/VulkanRenderer.h"

namespace RandomEngine::Graphics {

	RendererAPI* Renderer::_rendererAPI = nullptr;

	void Renderer::Init() {
		switch (GetAPI()) {
			case RendererAPI::API::OpenGL:
				_rendererAPI = new OpenGLRenderer;
				break;
			case RendererAPI::API::Vulkan:
				_rendererAPI = new VulkanRenderer;
				break;
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				_rendererAPI = nullptr;
				break;
		}
	}

	void Renderer::BeginScene() {

	}

	void Renderer::EndScene() {

	}

	void Renderer::Submit(const std::shared_ptr<VertexArray>& vertexArray) {
		vertexArray->Bind();
		RenderCommands::DrawIndexed(vertexArray);
	}

}
