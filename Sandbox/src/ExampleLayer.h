#pragma once

#include <RandomEngine.h>

namespace Sandbox {

	class ExampleLayer : public RandomEngine::Layer {

		private:
			std::shared_ptr<RandomEngine::Graphics::Shader> _shader;
			std::shared_ptr<RandomEngine::Graphics::VertexArray> _vertexArray;

			RandomEngine::Graphics::OrthographicCamera _camera;
			RandomEngine::Maths::Vector3f _cameraPosition;
			float _cameraSpeed = 3.5f;

		public:
			ExampleLayer();

			void OnUpdate(RandomEngine::Timestep timestep) override;
	};

}
