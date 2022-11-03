#include "ExampleLayer.h"

#include <memory>
#include <Platform/OpenGL/OpenGLShader.h>

namespace Sandbox {

	ExampleLayer::ExampleLayer() 
		: Layer("Example"), _camera(16.0f / 9.0f, true) {
		using namespace RandomEngine;
		using namespace RandomEngine::Graphics;
	
		auto rainbowShader = _shaderLibrary.Load("RainbowShader", "assets/shaders/rainbow.glsl");
		rainbowShader->Unbind();

		auto basicShader = _shaderLibrary.Load("BasicShader", "assets/shaders/basic.glsl");
		basicShader->Unbind();

		_cube = new Cube("Test Cube");
		_cube->SetPosition({ 0.0f, 0.0f, 0.0f });
		_cube->SetRotation({ 0.0f, 0.0f, 0.0f });
		_cube->SetScale({ 0.4f, 0.4f, 0.4f });
		_cube->SetColor({ 1.0f, 1.0f, 1.0f, 0.0f });

		_sprite = new Sprite("Test Sprite");
		_sprite->SetPosition({ 0.0f, 0.0f, 0.0f });
		_sprite->SetRotation({ 0.0f, 0.0f, 0.0f });
		_sprite->SetScale({ 1.0f, 1.0f, 1.0f });
		_sprite->SetColor({ 1.0f, 1.0f, 1.0f, 0.0f });

		basicShader->Bind();
		std::dynamic_pointer_cast<OpenGLShader>(basicShader)->Define("u_Texture", 0);
		basicShader->Unbind();
	}

	void ExampleLayer::OnGUIRender() {
		ImGui::Begin("Settings");
		ImGui::ColorEdit4("Color", _cube->GetColorPointer());
		ImGui::End();
	}

	void ExampleLayer::OnEvent(RandomEngine::Event& e) {
		_camera.OnEvent(e);
	}

	void ExampleLayer::OnUpdate(RandomEngine::UpdateArgs args) {
		using namespace RandomEngine::Graphics;

		_camera.OnUpdate(args.DeltaTime);

		MoveObject(_sprite, args.DeltaTime);

		RenderCommands::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		RenderCommands::Clear();

		Renderer::BeginScene(_camera.GetCamera());

		_sprite->GetTexture()->Bind();
		auto basicShader = _shaderLibrary.Get("BasicShader");
		Renderer::Submit(basicShader, _sprite->GetVertexArray(), _sprite->GetTransform());

		// std::dynamic_pointer_cast<OpenGLShader>(_rainbowShader)->Define("u_Color", _cube->GetColor());
		// Renderer::Submit(_rainbowShader, _cube->GetVertexArray(), _cube->GetTransform());

		Renderer::EndScene();
	}

	template<typename T>
	void ExampleLayer::MoveObject(T* obj, RandomEngine::Timestep timestep) {
		auto position = obj->GetTransform().Position;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_LEFT))
			position.x -= _objSpeed * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_RIGHT))
			position.x += _objSpeed * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_DOWN))
			position.y -= _objSpeed * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_UP))
			position.y += _objSpeed * timestep;

		obj->SetPosition(position);
	}

}
