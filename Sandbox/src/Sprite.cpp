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

		auto vertexBufferSize = sizeof(_vertices) / sizeof(*_vertices);
		auto vertexBufferData = RandomEngine::CreateRef<float[]>(vertexBufferSize);
		for (int i = 0; i < vertexBufferSize; i++) vertexBufferData[i] = _vertices[i];

		auto vertexBuffer = VertexBuffer::Create(vertexBufferData, vertexBufferSize);
		vertexBuffer->SetLayout(_layout);

		auto indexBufferSize = sizeof(_indices) / sizeof(*_indices);
		auto indexBufferData = RandomEngine::CreateRef<unsigned int[]>(indexBufferSize);
		for (int i = 0; i < indexBufferSize; i++) indexBufferData[i] = _indices[i];

		auto indexBuffer = IndexBuffer::Create(indexBufferData, indexBufferSize);

		_vertexArray = VertexArray::Create();
		_vertexArray->AddVertexBuffer(vertexBuffer);
		_vertexArray->SetIndexBuffer(indexBuffer);
		_vertexArray->Bind();

		_vertexArray->Unbind();
		vertexBuffer->Unbind();
		indexBuffer->Unbind();

		_texture = Texture2D::Create("assets/textures/mikasa.png");
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

	RandomEngine::Ref<RandomEngine::Graphics::Texture2D> Sprite::GetTexture() {
		return _texture;
	}

}
