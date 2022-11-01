#pragma once

#include <RandomEngine.h>
#include "Cube.h"
#include "Sprite.h"

namespace Sandbox {

	class ExampleLayer : public RandomEngine::Layer {

		private:
			RandomEngine::Graphics::ShaderLibrary _shaderLibrary;

			RandomEngine::Graphics::OrthographicCameraController _camera;
			Cube* _cube;
			Sprite* _sprite;
			float _objSpeed = 2.0f;

			template<typename T>
			void MoveObject(T* obj, RandomEngine::Timestep timestep);

		public:
			ExampleLayer();

			void OnUpdate(RandomEngine::Timestep timestep) override;
			void OnEvent(RandomEngine::Event& e) override;
			void OnGUIRender() override;
	};

}
