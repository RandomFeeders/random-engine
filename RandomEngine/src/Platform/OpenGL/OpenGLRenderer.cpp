#include "REPCH.h"
#include "OpenGLRenderer.h"

#include <glad/glad.h>

namespace RandomEngine::Graphics {



	void OpenGLRenderer::Init() {
		#ifdef RE_ENV_DEBUG
		glEnable(GL_DEBUG_OUTPUT);
		glEnable(GL_DEBUG_OUTPUT_SYNCHRONOUS);
		
		glDebugMessageCallback(OpenGLMessageCallback, nullptr);
		glDebugMessageControl(GL_DONT_CARE, GL_DONT_CARE, GL_DEBUG_SEVERITY_NOTIFICATION, 0, NULL, GL_FALSE);
		#endif

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glEnable(GL_DEPTH_TEST);
	}

	void OpenGLRenderer::Shutdown() {

	}

	void OpenGLRenderer::OpenGLMessageCallback(
		unsigned int source,
		unsigned int type,
		unsigned int id,
		unsigned int severity,
		int length,
		const char* message,
		const void* userParam
	) {
		switch (severity)
		{
			case GL_DEBUG_SEVERITY_HIGH:         
				RE_CORE_CRITICAL(message); 
				return;
			case GL_DEBUG_SEVERITY_MEDIUM:       
				RE_CORE_ERROR(message); return;
			case GL_DEBUG_SEVERITY_LOW:          
				RE_CORE_WARN(message); 
				return;
			case GL_DEBUG_SEVERITY_NOTIFICATION: 
				RE_CORE_TRACE(message); 
				return;
		}

		RE_CORE_ASSERT(false, "Unknown severity level!");
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

	void OpenGLRenderer::DrawIndexed(const VertexArrayRef& vertexArray, unsigned int indexCount) {
		glDrawElements(
			GL_TRIANGLES,
			indexCount == 0 ? vertexArray->GetIndexBuffer()->GetCount() : indexCount,
			GL_UNSIGNED_INT,
			nullptr
		);
	}

}
