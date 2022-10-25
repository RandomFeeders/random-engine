#pragma once

#include "RandomEngine/Graphics/Buffers/VertexBuffer.h"

namespace RandomEngine::Graphics {

	class OpenGLVertexBuffer : public VertexBuffer {

		private:
			unsigned int _rendererId;

		public:
			OpenGLVertexBuffer(float* data, unsigned int count);
			virtual ~OpenGLVertexBuffer();

			void Bind() const override;
			void Unbind() const override;
	};

}
