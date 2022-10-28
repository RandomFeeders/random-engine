#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Buffers/VertexBuffer.h"
#include "RandomEngine/Graphics/Buffers/IndexBuffer.h"

namespace RandomEngine::Graphics {

	class VertexArray;

	using VertexArrayRef = Ref<VertexArray>;

	class VertexArray {
	
		protected:
			List<VertexBufferRef> _vertexBuffers;
			IndexBufferRef _indexBuffer;

		public:
			VertexArray() = default;
			virtual ~VertexArray() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual void AddVertexBuffer(const VertexBufferRef buffer);
			virtual void SetIndexBuffer(const IndexBufferRef buffer);

			virtual inline const List<VertexBufferRef>& GetVertexBuffers() const { return _vertexBuffers; }
			virtual inline const IndexBufferRef& GetIndexBuffer() const { return _indexBuffer; }

			static VertexArrayRef Create();
	};

}
