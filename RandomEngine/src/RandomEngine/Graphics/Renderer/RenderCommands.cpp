#include "REPCH.h"
#include "RenderCommands.h"

#include "Renderer.h"

namespace RandomEngine::Graphics {

	void RenderCommands::Clear() {
		Renderer::_rendererAPI->Clear();
	}

	void RenderCommands::SetClearColor(const Maths::Vector4f& color) {
		Renderer::_rendererAPI->SetClearColor(color);
	}

	void RenderCommands::DrawIndexed(const VertexArrayRef& vertexArray) {
		Renderer::_rendererAPI->DrawIndexed(vertexArray);
	}

}
