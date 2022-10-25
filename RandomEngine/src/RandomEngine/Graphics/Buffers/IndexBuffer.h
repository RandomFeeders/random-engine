#pragma once

#include "Buffer.h"

namespace RandomEngine::Graphics {

	class IndexBuffer : public Buffer<unsigned int> {

		public:
			IndexBuffer(unsigned int* data, unsigned int count);
			virtual ~IndexBuffer() = default;

			void Bind() const override = 0;
			void Unbind() const override = 0;

			static IndexBuffer* Create(unsigned int* data, unsigned int count);
	};

}
