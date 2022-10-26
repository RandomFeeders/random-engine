#pragma once

#include "RandomEngine/Graphics/Buffers/VertexArray.h"

namespace RandomEngine::Graphics {

	class OpenGLVertexArray : public VertexArray
	{
		private:
			unsigned int _rendererId;

		public:
			OpenGLVertexArray();
			virtual ~OpenGLVertexArray();

			void Bind() const override;
			void Unbind() const override;

			void AddVertexBuffer(const std::shared_ptr<VertexBuffer> buffer) override;
			void SetIndexBuffer(const std::shared_ptr<IndexBuffer> buffer) override;
	};

}



