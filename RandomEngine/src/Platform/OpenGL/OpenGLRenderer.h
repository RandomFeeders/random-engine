#pragma once

#include "RandomEngine/Graphics/Renderer/RendererAPI.h"

namespace RandomEngine::Graphics {

	class OpenGLRenderer : public RendererAPI {

		public:
			void Init() override;
			void Shutdown() override;

			void Clear() override;
			void SetClearColor(const Maths::Vector4f& color) override;
			void SetViewport(unsigned int x, unsigned int y, unsigned int width, unsigned int height) override;

			void DrawIndexed(const VertexArrayRef& vertexArray) override;

			static void OpenGLMessageCallback(
				unsigned int source,
				unsigned int type,
				unsigned int id,
				unsigned int severity,
				int length,
				const char* message,
				const void* userParam
			);
	};

}
