#pragma once

#include "RendererAPI.h"
#include "RenderCommands.h"
#include "RandomEngine/Maths/Maths.h"
#include "RandomEngine/Graphics/Shader.h"
#include "RandomEngine/Graphics/Cameras/OrthographicCamera.h"

namespace RandomEngine::Graphics {

	class Renderer {
		friend class RenderCommands;

		private:
			struct SceneData {
				Maths::Matrix4f ViewProjectionMatrix;
			};

			static RendererAPI* _rendererAPI;
			static SceneData* _sceneData;

		public:
			static void Init();

			static void BeginScene(OrthographicCamera& camera);
			static void EndScene();

			static void Submit(
				const std::shared_ptr<Shader>& shader, 
				const std::shared_ptr<VertexArray>& vertexArray,
				const Maths::Matrix4f& transform = Maths::Matrix4f::Identity()
			);

			static inline RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}
