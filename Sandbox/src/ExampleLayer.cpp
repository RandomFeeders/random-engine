#include "ExampleLayer.h"

#include <memory>
#include <Platform/OpenGL/OpenGLShader.h>
#include "FileUtils.h"

namespace Sandbox {

	ExampleLayer::ExampleLayer() 
		: Layer("Example"), 
		  _camera(0.9f, 1.6f, -0.9f, -1.6f),
	      _cubePosition(0.0f),
		  _cubeRotation(0.0f),
	      _cubeScale(1.0f),
		  _cubeColor(1.0f, 1.0f, 1.0f, 0.0f) {
		using namespace RandomEngine::Graphics;

		_vertexArray.reset(VertexArray::Create());

		float vertices[7 * 7] = {
			-0.45f, -0.30f, 0.00f, 0.8f, 0.8f, 0.2f, 1.0f,	// A - 0
			 0.00f, -0.50f, 0.00f, 0.8f, 0.2f, 0.8f, 1.0f,	// B - 1
			 0.00f,  0.05f, 0.00f, 0.2f, 0.8f, 0.8f, 1.0f,	// C - 2
			-0.45f,  0.30f, 0.00f, 0.2f, 0.2f, 0.8f, 1.0f,	// D - 3
			 0.45f, -0.30f, 0.00f, 0.2f, 0.8f, 0.2f, 1.0f,	// E - 4
			 0.45f,  0.30f, 0.00f, 0.8f, 0.2f, 0.2f, 1.0f,	// F - 5
			 0.00f,  0.50f, 0.00f, 0.8f, 0.2f, 0.8f, 1.0f	// G - 6
		};

		std::shared_ptr<VertexBuffer> vertexBuffer;
		vertexBuffer.reset(VertexBuffer::Create(vertices, 7 * 7));

		BufferLayout layout = {
			{ "_position", ShaderDataType::Vector3f },
			{ "_color", ShaderDataType::Vector4f }
		};

		vertexBuffer->SetLayout(layout);

		unsigned int indices[3 * 6] = {
			0, 1, 2,
			2, 3, 0,
			1, 4, 5,
			5, 2, 1,
			3, 2, 5,
			5, 6, 3
		};

		std::shared_ptr<IndexBuffer> indexBuffer;
		indexBuffer.reset(IndexBuffer::Create(indices, 3 * 6));

		_vertexArray->AddVertexBuffer(vertexBuffer);
		_vertexArray->SetIndexBuffer(indexBuffer);
		_vertexArray->Bind();

		const std::string& vertexSrc = FileUtils::ReadFile("src/Shaders/basic.vert");
		const std::string& fragmentSrc = FileUtils::ReadFile("src/Shaders/basic.frag");
		
		_shader.reset(Shader::Create(vertexSrc, fragmentSrc));
	}

	void ExampleLayer::OnGUIRender() {
		ImGui::Begin("Settings");
		ImGui::ColorEdit4("Color", _cubeColor);
		ImGui::End();
	}

	void ExampleLayer::OnUpdate(RandomEngine::Timestep timestep) {
		using namespace RandomEngine::Graphics;
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

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_LEFT))
			_cubePosition.x -= _cubeSpeed * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_RIGHT))
			_cubePosition.x += _cubeSpeed * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_DOWN))
			_cubePosition.y -= _cubeSpeed * timestep;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_UP))
			_cubePosition.y += _cubeSpeed * timestep;

		RenderCommands::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		RenderCommands::Clear();

		Renderer::BeginScene(_camera);

		_cubeScale = { 0.1f, 0.1f, 0.1f };

		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				Vector3f pos = { x * 0.11f - 0.22f, y * 0.11f - 0.22f, 0.0f };

				Transform transform(pos, _cubeRotation, _cubeScale);

				Renderer::Submit(_shader, _vertexArray, transform);
			}
		}

		_cubeScale = { 0.2f, 0.2f, 0.2f };

		Transform transform(_cubePosition, _cubeRotation, _cubeScale);

		std::dynamic_pointer_cast<OpenGLShader>(_shader)->Define("u_Color", _cubeColor);
		Renderer::Submit(_shader, _vertexArray, transform);

		Renderer::EndScene();
	}

}
