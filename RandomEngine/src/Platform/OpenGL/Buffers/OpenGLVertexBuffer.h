#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Buffers/VertexBuffer.h"

namespace RandomEngine::Graphics {

	class OpenGLVertexBuffer : public VertexBuffer {

		private:
			unsigned int _rendererId;

		public:
			OpenGLVertexBuffer(unsigned int count);
			OpenGLVertexBuffer(const Ref<float[]>& data, unsigned int count);
			virtual ~OpenGLVertexBuffer();

			void Bind() const override;
			void Unbind() const override;
			void SetData(const Ref<float[]>& data, unsigned int count) override;

			void SetLayout(const BufferLayout& layout) override;
	};

}
