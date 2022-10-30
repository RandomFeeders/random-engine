#include "Cube.h"

namespace Sandbox {

	float Cube::_vertices[] = {
			-0.45f, -0.30f, 0.00f, 0.8f, 0.8f, 0.2f, 1.0f,	// A - 0
			 0.00f, -0.50f, 0.00f, 0.8f, 0.2f, 0.8f, 1.0f,	// B - 1
			 0.00f,  0.05f, 0.00f, 0.2f, 0.8f, 0.8f, 1.0f,	// C - 2
			-0.45f,  0.30f, 0.00f, 0.2f, 0.2f, 0.8f, 1.0f,	// D - 3
			 0.45f, -0.30f, 0.00f, 0.2f, 0.8f, 0.2f, 1.0f,	// E - 4
			 0.45f,  0.30f, 0.00f, 0.8f, 0.2f, 0.2f, 1.0f,	// F - 5
			 0.00f,  0.50f, 0.00f, 0.8f, 0.2f, 0.8f, 1.0f	// G - 6
	};

	unsigned int Cube::_indices[] = {
			0, 1, 2,
			2, 3, 0,
			1, 4, 5,
			5, 2, 1,
			3, 2, 5,
			5, 6, 3
	};

	RandomEngine::Graphics::BufferLayout Cube::_layout = {
		{ "_position", ShaderDataType::Vector3f },
		{ "_color", ShaderDataType::Vector4f }
	};

	Cube::Cube(const RandomEngine::String& name) {
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

	void Cube::SetPosition(RandomEngine::Maths::Vector3f position) {
		_transform.Position = position;
	}

	void Cube::SetRotation(RandomEngine::Maths::Vector3f rotation) {
		_transform.Rotation = rotation;
	}

	void Cube::SetScale(RandomEngine::Maths::Vector3f scale) {
		_transform.Scale = scale;
	}

	void Cube::SetColor(RandomEngine::Maths::Vector4f color) {
		_color = color;
	}

	RandomEngine::Graphics::Transform Cube::GetTransform() {
		return _transform;
	}

	RandomEngine::Graphics::VertexArrayRef Cube::GetVertexArray() {
		return _vertexArray;
	}

	RandomEngine::Maths::Vector4f Cube::GetColor() {
		return _color;
	}

	float* Cube::GetColorPointer() {
		return _color;
	}

}
