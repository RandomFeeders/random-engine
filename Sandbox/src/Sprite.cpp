#include "Sprite.h"

namespace Sandbox {

	float Sprite::_vertices[] = { 
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
		 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
		 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
	};

	unsigned int Sprite::_indices[] = { 
		0, 1, 2,
		2, 3, 0
	};

	RandomEngine::Graphics::BufferLayout Sprite::_layout = {
		{ "_position", ShaderDataType::Vector3f },
		{ "_texCoord", ShaderDataType::Vector2f }
	};

	Sprite::Sprite(const RandomEngine::String& name) {
		using namespace RandomEngine::Graphics;

		auto vertexBuffer = VertexBuffer::Create(_vertices, sizeof(_vertices) / sizeof(*_vertices));
		vertexBuffer->SetLayout(_layout);

		auto indexBuffer = IndexBuffer::Create(_indices, sizeof(_indices) / sizeof(*_indices));

		_vertexArray = VertexArray::Create();
		_vertexArray->AddVertexBuffer(vertexBuffer);
		_vertexArray->SetIndexBuffer(indexBuffer);
		_vertexArray->Bind();

		_vertexArray->Unbind();
		vertexBuffer->Unbind();
		indexBuffer->Unbind();
	}

	void Sprite::SetPosition(RandomEngine::Maths::Vector3f position) {
		_transform.Position = position;
	}

	void Sprite::SetRotation(RandomEngine::Maths::Vector3f rotation) {
		_transform.Rotation = rotation;
	}

	void Sprite::SetScale(RandomEngine::Maths::Vector3f scale) {
		_transform.Scale = scale;
	}

	void Sprite::SetColor(RandomEngine::Maths::Vector4f color) {
		_color = color;
	}

	RandomEngine::Graphics::Transform Sprite::GetTransform() {
		return _transform;
	}

	RandomEngine::Graphics::VertexArrayRef Sprite::GetVertexArray() {
		return _vertexArray;
	}

	RandomEngine::Maths::Vector4f Sprite::GetColor() {
		return _color;
	}

	float* Sprite::GetColorPointer() {
		return _color;
	}

}
