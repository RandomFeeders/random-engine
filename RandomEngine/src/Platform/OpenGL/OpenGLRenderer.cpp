#include "REPCH.h"
#include "OpenGLRenderer.h"

#include <glad/glad.h>

namespace RandomEngine::Graphics {

	void OpenGLRenderer::Init() {
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}

	void OpenGLRenderer::Shutdown() {

	}

	void OpenGLRenderer::Clear() {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	}

	void OpenGLRenderer::SetClearColor(const Maths::Vector4f& color) {
		glClearColor(color.r, color.g, color.b, color.a);
	}

	void OpenGLRenderer::SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
		glViewport(x, y, width, height);
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
