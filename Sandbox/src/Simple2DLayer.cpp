#include "Simple2DLayer.h"

namespace Sandbox {

	Simple2DLayer::Simple2DLayer() 
		: Layer("Simple2D") { }

	void Simple2DLayer::OnAttach() { 
		using namespace RandomEngine;
		_cameraController = CreateScope<Graphics::OrthographicCameraController>(16.0f / 9.0f);
		_shader = Graphics::Shader::Create("assets/shaders/rainbow.glsl", "RainbowShader");
		_shader->Unbind();

		_cube = CreateScope<Cube>("Test Cube");
		_cube->SetPosition({ 0.0f, 0.0f, 0.0f });
		_cube->SetRotation({ 0.0f, 0.0f, 0.0f });
		_cube->SetScale({ 0.4f, 0.4f, 0.4f });
		_cube->SetColor({ 1.0f, 1.0f, 1.0f, 0.0f });
	}

	void Simple2DLayer::OnDetach() {
		_cameraController.reset(nullptr);
		_cube.reset(nullptr);
	}

	void Simple2DLayer::OnUpdate(RandomEngine::UpdateArgs args) {
		using namespace RandomEngine;

		Profiling::Timer timer(
			"Simple2DLayer::OnUpdate", 
			[&](Profiling::Timer::Result result) { _results.push_back(result); }
		);

		_cameraController->OnUpdate(args.DeltaTime);

		Graphics::RenderCommands::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		Graphics::RenderCommands::Clear();

		Graphics::Renderer::BeginScene(_cameraController->GetCamera());

		_shader->Define("u_Color", _cube->GetColor());
		Graphics::Renderer::Submit(_shader, _cube->GetVertexArray(), _cube->GetTransform());

		/*
		Graphics::Renderer2D::DrawQuad({
				{ 0.0f, 0.0f, 0.0f },
				{ 0.0f, 0.0f, 0.0f },
				{ 1.0f, 1.0f, 0.0f }
			}, { 0.2f, 0.5f, 0.8f, 1.0f });*/

		Graphics::Renderer::EndScene();
	}

	void Simple2DLayer::OnEvent(RandomEngine::Event& e) { 
		_cameraController->OnEvent(e);
	}

	void Simple2DLayer::OnGUIRender() { 
		ImGui::Begin("Settings");
		ImGui::ColorEdit4("Color", _cube->GetColorPointer());
		ImGui::End();

		ImGui::Begin("Profiling");

		for (auto& result : _results) {
			ImGui::Text(result.ToString().c_str());
		}
		_results.clear();

		ImGui::End();
	}

}
