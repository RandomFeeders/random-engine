#include "ExampleLayer.h"

#include <memory>
#include <Platform/OpenGL/OpenGLShader.h>
#include "FileUtils.h"

namespace Sandbox {

	ExampleLayer::ExampleLayer() 
		: Layer("Example"), _camera(0.9f, 1.6f, -0.9f, -1.6f) {
		using namespace RandomEngine;
		using namespace RandomEngine::Graphics;

		const RandomEngine::String& rVertexSrc = FileUtils::ReadFile("assets/shaders/rainbow.vert");
		const RandomEngine::String& rFragmentSrc = FileUtils::ReadFile("assets/shaders/rainbow.frag");		
		_rainbowShader = Shader::Create(rVertexSrc, rFragmentSrc);
		_rainbowShader->Unbind();

		const RandomEngine::String& bVertexSrc = FileUtils::ReadFile("assets/shaders/basic.vert");
		const RandomEngine::String& bFragmentSrc = FileUtils::ReadFile("assets/shaders/basic.frag");
		_basicShader = Shader::Create(bVertexSrc, bFragmentSrc);
		_basicShader->Unbind();

		_cube = new Cube("Test Cube");
		_cube->SetPosition({ 0.0f, 0.0f, 0.0f });
		_cube->SetRotation({ 0.0f, 0.0f, 0.0f });
		_cube->SetScale({ 0.4f, 0.4f, 0.4f });
		_cube->SetColor({ 1.0f, 1.0f, 1.0f, 0.0f });

		_sprite = new Sprite("Test Sprite");
		_sprite->SetPosition({ 0.0f, 0.0f, 0.0f });
		_sprite->SetRotation({ 0.0f, 0.0f, 0.0f });
		_sprite->SetScale({ 0.4f, 0.4f, 0.4f });
		_sprite->SetColor({ 1.0f, 1.0f, 1.0f, 0.0f });
	}

	void ExampleLayer::OnGUIRender() {
		ImGui::Begin("Settings");
		ImGui::ColorEdit4("Color", _cube->GetColorPointer());
		ImGui::End();
	}

	void ExampleLayer::OnUpdate(RandomEngine::Timestep timestep) {
		using namespace RandomEngine::Graphics;

		MoveCamera(timestep);
		MoveObject(_sprite, timestep);		

		RenderCommands::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		RenderCommands::Clear();

		Renderer::BeginScene(_camera);

		Renderer::Submit(_basicShader, _sprite->GetVertexArray(), _sprite->GetTransform());

		// std::dynamic_pointer_cast<OpenGLShader>(_rainbowShader)->Define("u_Color", _cube->GetColor());
		// Renderer::Submit(_rainbowShader, _cube->GetVertexArray(), _cube->GetTransform());

		Renderer::EndScene();
	}

	void ExampleLayer::MoveCamera(RandomEngine::Timestep timestep) {
		using namespace RandomEngine::Maths;

		Vector3f camPos = _camera.GetPosition();
		Vector3f camRot = _camera.GetRotation();

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_A))
			camPos.x -= _cameraSpeed * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_D))
			camPos.x += _cameraSpeed * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_S))
			camPos.y -= _cameraSpeed * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_W))
			camPos.y += _cameraSpeed * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_Q))
			camRot.z += _cameraSpeed * 5 * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_E))
			camRot.z -= _cameraSpeed * 5 * timestep;

		_camera.SetPosition(camPos);
		_camera.SetRotation(camRot);
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
