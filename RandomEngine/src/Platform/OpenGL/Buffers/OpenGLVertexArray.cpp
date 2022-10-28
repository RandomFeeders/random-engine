#include "REPCH.h"
#include "OpenGLVertexArray.h"

#include "Platform/OpenGL/OpenGLShaderDataType.h"

namespace RandomEngine::Graphics {

	OpenGLVertexArray::OpenGLVertexArray() {
		glCreateVertexArrays(1, &_rendererId);
		glBindVertexArray(_rendererId);
	}

	OpenGLVertexArray::~OpenGLVertexArray() {
		glDeleteVertexArrays(1, &_rendererId);
		_rendererId = NULL;
	}

	void OpenGLVertexArray::Bind() const {
		glBindVertexArray(_rendererId);
	}

	void OpenGLVertexArray::Unbind() const {
		glBindVertexArray(NULL);
	}

	void OpenGLVertexArray::AddVertexBuffer(const VertexBufferRef buffer) {
		RE_CORE_ASSERT(buffer->GetLayout().GetElements().size(), "Vertex buffers must have a layout!");
		
		glBindVertexArray(_rendererId);
		buffer->Bind();
		
		const auto& layout = buffer->GetLayout();
		unsigned int index = 0;
		for (const auto& element : layout) {
			glEnableVertexAttribArray(index);
			glVertexAttribPointer(
				index,
				element.ComponentCount,
				ShaderDataTypeToOpenGLDataType(element.Type),
				element.Normalized ? GL_TRUE : GL_FALSE,
				layout.GetStride(),
				(const void*) element.Offset
			);
			index++;
		}

		__super::AddVertexBuffer(buffer);
	}

	void OpenGLVertexArray::SetIndexBuffer(const IndexBufferRef buffer) {
		glBindVertexArray(_rendererId);
		buffer->Bind();

		__super::SetIndexBuffer(buffer);
	}

}
