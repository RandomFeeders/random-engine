#pragma once

#include "Buffer.h"
#include "BufferLayout.h"

namespace RandomEngine::Graphics {

	class VertexBuffer : public Buffer<float> {

		protected:
			BufferLayout _layout;

		public:
			VertexBuffer(float* data, unsigned int count);
			virtual ~VertexBuffer() = default;

			void Bind() const override = 0;
			void Unbind() const override = 0;

			virtual void SetLayout(const BufferLayout& layout);
			inline const BufferLayout& GetLayout() const { return _layout; }

			static VertexBuffer* Create(float* data, unsigned int count);
	};

}
