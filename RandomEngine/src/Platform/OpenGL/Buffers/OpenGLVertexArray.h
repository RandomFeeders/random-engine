#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Buffers/VertexArray.h"

namespace RandomEngine::Graphics {

	class OpenGLVertexArray : public VertexArray
	{
		private:
			unsigned int _rendererId;
			unsigned int _vertexBufferIndex;

		public:
			OpenGLVertexArray();
			virtual ~OpenGLVertexArray();

			void Bind() const override;
			void Unbind() const override;

			void AddVertexBuffer(const VertexBufferRef buffer) override;
			void SetIndexBuffer(const IndexBufferRef buffer) override;
	};

}



