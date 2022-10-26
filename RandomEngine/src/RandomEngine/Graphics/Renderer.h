#pragma once

#include "RendererAPI.h"
#include "RenderCommands.h"

namespace RandomEngine::Graphics {

	class Renderer {
		friend class RenderCommands;

		private:
			static RendererAPI* _rendererAPI;

		public:
			static void Init();

			static void BeginScene();
			static void EndScene();

			static void Submit(const std::shared_ptr<VertexArray>& vertexArray);

			static inline RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}
