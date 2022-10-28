#include "REPCH.h"
#include "OpenGLVertexBuffer.h"

#include <glad/glad.h>

namespace RandomEngine::Graphics {
	
	OpenGLVertexBuffer::OpenGLVertexBuffer(float* data, unsigned int count)
		: VertexBuffer(data, count) {
		glCreateBuffers(1, &_rendererId);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
		glBufferData(GL_ARRAY_BUFFER, GetSize(), data, GL_STATIC_DRAW);
	}

	OpenGLVertexBuffer::~OpenGLVertexBuffer() {
		glDeleteBuffers(1, &_rendererId);
		_rendererId = NULL;
	}

	void OpenGLVertexBuffer::Bind() const {
		glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
	}

	void OpenGLVertexBuffer::Unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, NULL);
	}

	void OpenGLVertexBuffer::SetLayout(const BufferLayout& layout) {
		__super::SetLayout(layout);
	}

}
