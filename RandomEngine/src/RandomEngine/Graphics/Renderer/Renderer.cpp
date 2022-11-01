#include "REPCH.h"
#include "Renderer.h"

#include "Platform/OpenGL/OpenGLRenderer.h"
#include "Platform/Vulkan/VulkanRenderer.h"
#include "Platform/OpenGL/OpenGLShader.h"

namespace RandomEngine::Graphics {

	Scope<RendererAPI> Renderer::_rendererAPI;
	Scope<Renderer::SceneData> Renderer::_sceneData = Scope<Renderer::SceneData>(new Renderer::SceneData);

	void Renderer::Init() {
		switch (GetAPI()) {
			case RendererAPI::API::OpenGL:
				_rendererAPI = Scope<RendererAPI>(new OpenGLRenderer);
				_rendererAPI->Init();
				break;
			case RendererAPI::API::Vulkan:
				_rendererAPI = Scope<RendererAPI>(new VulkanRenderer);
				_rendererAPI->Init();
				break;
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				_rendererAPI = nullptr;
				break;
		}
	}

	void Renderer::OnWindowResized(unsigned int width, unsigned int height) {
		_rendererAPI->SetViewport(0, 0, width, height);
	}

	void Renderer::BeginScene(const OrthographicCamera& camera) {
		_sceneData->ViewProjectionMatrix = camera.GetViewProjectionMatrix();
	}

	void Renderer::EndScene() {

	}

	void Renderer::Submit(
		const ShaderRef& shader,
		const VertexArrayRef& vertexArray,
		const Maths::Matrix4f& transform
	) {
		shader->Bind();

		std::dynamic_pointer_cast<OpenGLShader>(shader)->Define("u_ViewProjection", _sceneData->ViewProjectionMatrix);
		std::dynamic_pointer_cast<OpenGLShader>(shader)->Define("u_Transform", transform);

		vertexArray->Bind();
		_rendererAPI->DrawIndexed(vertexArray);
	}

}
