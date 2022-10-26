#include "REPCH.h"

#include "OpenGLIndexBuffer.h"

#include <glad/glad.h>

namespace RandomEngine::Graphics {

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int* data, unsigned int count)
		: IndexBuffer(data, count) {
		glCreateBuffers(1, &_rendererId);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererId);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, GetSize(), data, GL_STATIC_DRAW);
	}

	OpenGLIndexBuffer::~OpenGLIndexBuffer() {
		glDeleteBuffers(1, &_rendererId);
		_rendererId = NULL;
	}

	void OpenGLIndexBuffer::Bind() const {
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _rendererId);
	}

	void OpenGLIndexBuffer::Unbind() const {
		glBindBuffer(GL_ARRAY_BUFFER, NULL);
	}

}
