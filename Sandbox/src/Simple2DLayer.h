#pragma once

#include "RandomEngine.h"
#include "Cube.h"

namespace Sandbox {

	class Simple2DLayer : public RandomEngine::Layer {

		struct ProfileResult {
			RandomEngine::String Name;
			float Duration;
		};

		private:
			RandomEngine::Graphics::ShaderRef _shader;
			RandomEngine::Scope<RandomEngine::Graphics::OrthographicCameraController> _cameraController;
			RandomEngine::Scope<Cube> _cube;
			std::vector<RandomEngine::Profiling::Timer::Result> _results;

		public:
			Simple2DLayer();

			void OnAttach() override;
			void OnDetach() override;
			void OnUpdate(RandomEngine::UpdateArgs args) override;
			void OnEvent(RandomEngine::Event& e) override;
			void OnGUIRender() override;
	};

}
