#include "REPCH.h"
#include "OpenGLVertexBuffer.h"

#include <glad/glad.h>

namespace RandomEngine::Graphics {
	
	OpenGLVertexBuffer::OpenGLVertexBuffer(unsigned int count)
		: VertexBuffer(count) {
		glCreateBuffers(1, &_rendererId);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
		glBufferData(GL_ARRAY_BUFFER, GetSize(), nullptr, GL_DYNAMIC_DRAW);
	}

	OpenGLVertexBuffer::OpenGLVertexBuffer(const Ref<float[]>& data, unsigned int count)
		: VertexBuffer(data, count) {
		glCreateBuffers(1, &_rendererId);
		glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
		glBufferData(GL_ARRAY_BUFFER, GetSize(), data.get(), GL_STATIC_DRAW);
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

	void OpenGLVertexBuffer::SetData(const Ref<float[]>& data, unsigned int count) {
		__super::SetData(data, count);

		glBindBuffer(GL_ARRAY_BUFFER, _rendererId);
		glBufferSubData(GL_ARRAY_BUFFER, 0, GetSize(), _data.get());
	}

	void OpenGLVertexBuffer::SetLayout(const BufferLayout& layout) {
		__super::SetLayout(layout);
	}

}
