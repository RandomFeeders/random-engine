#include "REPCH.h"
#include "OpenGLIndexBuffer.h"

#include <glad/glad.h>

namespace RandomEngine::Graphics {

	OpenGLIndexBuffer::OpenGLIndexBuffer(unsigned int count)
		: IndexBuffer(count) {
		glCreateBuffers(1, &_rendererId);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
		glBufferData(GL_ARRAY_BUFFER, GetSize(), nullptr, GL_DYNAMIC_DRAW);
	}

	OpenGLIndexBuffer::OpenGLIndexBuffer(const Ref<unsigned int[]>& data, unsigned int count)
		: IndexBuffer(data, count) {
		glCreateBuffers(1, &_rendererId);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
		glBufferData(GL_ARRAY_BUFFER, GetSize(), data.get(), GL_STATIC_DRAW);
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
