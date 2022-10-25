#pragma once

#include "Buffer.h"

namespace RandomEngine::Graphics {

	class VertexBuffer : public Buffer<float> {

		public:
			VertexBuffer(float* data, unsigned int count);
			virtual ~VertexBuffer() = default;

			void Bind() const override = 0;
			void Unbind() const override = 0;

			static VertexBuffer* Create(float* data, unsigned int count);
	};

}
