#include "ExampleLayer.h"

#include "FileUtils.h"

namespace Sandbox {

	ExampleLayer::ExampleLayer() 
		: Layer("Example"), _camera(0.9f, 1.6f, -0.9f, -1.6f) { 
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

		_shader.reset(new Shader(vertexSrc, fragmentSrc));
	}

	void ExampleLayer::OnUpdate() {
		using namespace RandomEngine::Graphics;
		using namespace RandomEngine::Maths;

		Vector3f camPos = _camera.GetPosition();
		Vector3f camRot = _camera.GetRotation();

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_A))
			camPos.x -= _cameraSpeed;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_D))
			camPos.x += _cameraSpeed;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_S))
			camPos.y -= _cameraSpeed;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_W))
			camPos.y += _cameraSpeed;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_Q))
			camRot.z += _cameraSpeed * 3;

		if (RandomEngine::Input::IsKeyPressed(RE_KEY_E))
			camRot.z -= _cameraSpeed * 3;

		_camera.SetPosition(camPos);
		_camera.SetRotation(camRot);

		RenderCommands::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		RenderCommands::Clear();

		Renderer::BeginScene(_camera);
		Renderer::Submit(_shader, _vertexArray);
		Renderer::EndScene();
	}

}
