#include "REPCH.h"
#include "OpenGLRenderer.h"

#include <glad/glad.h>

namespace RandomEngine::Graphics {

	void OpenGLRenderer::Init() {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	}

	void OpenGLRenderer::Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRenderer::SetClearColor(const Maths::Vector4f& color) {
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRenderer::DrawIndexed(const VertexArrayRef& vertexArray) {
		glDrawElements(
			GL_TRIANGLES,
			vertexArray->GetIndexBuffer()->GetCount(),
			GL_UNSIGNED_INT,
			nullptr
		);
	}

}
