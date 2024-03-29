#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Buffers/Buffer.h"
#include "RandomEngine/Graphics/Buffers/BufferLayout.h"

namespace RandomEngine::Graphics {

	class VertexBuffer;

	using VertexBufferRef = Ref<VertexBuffer>;

	class VertexBuffer : public Buffer<float> {

		protected:
			BufferLayout _layout;

		public:
			VertexBuffer(unsigned int count);
			VertexBuffer(const Ref<float[]>& data, unsigned int count);
			virtual ~VertexBuffer() = default;

			void Bind() const override = 0;
			void Unbind() const override = 0;

			virtual void SetLayout(const BufferLayout& layout);
			inline const BufferLayout& GetLayout() const { return _layout; }

			static VertexBufferRef Create(unsigned int count);
			static VertexBufferRef Create(const Ref<float[]>& data, unsigned int count);
	};

}
