#include "REPCH.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLRenderer.h"
#include "Platform/Vulkan/VulkanRenderer.h"

namespace RandomEngine::Graphics {

	RendererAPI* Renderer::_rendererAPI = nullptr;
	Renderer::SceneData* Renderer::_sceneData = new Renderer::SceneData;

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

	void Renderer::BeginScene(OrthographicCamera& camera) {
		_sceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene() {

	}

	void Renderer::Submit(
		const std::shared_ptr<Shader>& shader, 
		const std::shared_ptr<VertexArray>& vertexArray,
		const Maths::Matrix4f& transform
	) {
		shader->Bind();
		shader->Define("u_ViewProjection", _sceneData->ViewProjectionMatrix);
		shader->Define("u_Transform", transform);

		vertexArray->Bind();
		RenderCommands::DrawIndexed(vertexArray);
	}

}
