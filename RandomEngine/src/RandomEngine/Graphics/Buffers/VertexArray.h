#pragma once

#include <memory>
#include "VertexBuffer.h"
#include "IndexBuffer.h"

namespace RandomEngine::Graphics {

	class VertexArray {
	
		protected:
			std::vector<std::shared_ptr<VertexBuffer>> _vertexBuffers;
			std::shared_ptr<IndexBuffer> _indexBuffer;

		public:
			VertexArray() = default;
			virtual ~VertexArray() = default;

			virtual void Bind() const = 0;
			virtual void Unbind() const = 0;

			virtual void AddVertexBuffer(const std::shared_ptr<VertexBuffer> buffer);
			virtual void SetIndexBuffer(const std::shared_ptr<IndexBuffer> buffer);

			virtual inline const std::vector<std::shared_ptr<VertexBuffer>>& GetVertexBuffers() const { return _vertexBuffers; }
			virtual inline const std::shared_ptr<IndexBuffer>& GetIndexBuffer() const { return _indexBuffer; }

			static VertexArray* Create();
	};

}
