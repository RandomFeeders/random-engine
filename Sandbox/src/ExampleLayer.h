#pragma once

#include <RandomEngine.h>
#include "Cube.h"
#include "Sprite.h"

namespace Sandbox {

	class ExampleLayer : public RandomEngine::Layer {

		private:
			RandomEngine::Graphics::ShaderRef _rainbowShader;
			RandomEngine::Graphics::ShaderRef _basicShader;

			RandomEngine::Graphics::OrthographicCamera _camera;
			RandomEngine::Maths::Vector3f _cameraPosition;
			Cube* _cube;
			Sprite* _sprite;
			float _cameraSpeed = 3.5f;
			float _objSpeed = 2.0f;

			void MoveCamera(RandomEngine::Timestep timestep);

			template<typename T>
			void MoveObject(T* obj, RandomEngine::Timestep timestep);

		public:
			ExampleLayer();

			void OnUpdate(RandomEngine::Timestep timestep) override;
			void OnGUIRender() override;
	};

}
