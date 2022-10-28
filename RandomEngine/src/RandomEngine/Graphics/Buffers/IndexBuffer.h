#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Buffers/Buffer.h"

namespace RandomEngine::Graphics {

	class IndexBuffer;

	using IndexBufferRef = Ref<IndexBuffer>;

	class IndexBuffer : public Buffer<unsigned int> {

		public:
			IndexBuffer(unsigned int* data, unsigned int count);
			virtual ~IndexBuffer() = default;

			void Bind() const override = 0;
			void Unbind() const override = 0;

			static IndexBufferRef Create(unsigned int* data, unsigned int count);
	};

}
