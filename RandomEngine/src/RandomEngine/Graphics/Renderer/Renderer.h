#pragma once

#include "RandomEngine/Maths/Maths.h"
#include "RandomEngine/Graphics/Renderer/RendererAPI.h"
#include "RandomEngine/Graphics/Renderer/RenderCommands.h"
#include "RandomEngine/Graphics/Cameras/OrthographicCamera.h"
#include "RandomEngine/Graphics/Shader/Shader.h"

namespace RandomEngine::Graphics {

	class Renderer {
		friend class RenderCommands;

		private:
			struct SceneData {
				Maths::Matrix4f ViewProjectionMatrix;
			};

			static Scope<RendererAPI> _rendererAPI;
			static Scope<SceneData> _sceneData;

		public:
			static void Init();

			static void BeginScene(const OrthographicCamera& camera);
			static void EndScene();

			static void Submit(
				const ShaderRef& shader, 
				const VertexArrayRef& vertexArray,
				const Maths::Matrix4f& transform = Maths::Matrix4f::Identity()
			);

			static inline RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }
	};

}
