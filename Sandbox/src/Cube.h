#pragma once

#include "RandomEngine.h"

namespace Sandbox {

	class Cube {

		private:
			RandomEngine::Graphics::VertexArrayRef _vertexArray;
			RandomEngine::Graphics::Transform _transform;
			RandomEngine::Maths::Vector4f _color;

			static float _vertices[];
			static unsigned int _indices[];
			static RandomEngine::Graphics::BufferLayout _layout;

		public:
			Cube(const RandomEngine::String& name);

			void SetPosition(RandomEngine::Maths::Vector3f position);
			void SetRotation(RandomEngine::Maths::Vector3f rotation);
			void SetScale(RandomEngine::Maths::Vector3f scale);
			void SetColor(RandomEngine::Maths::Vector4f color);

			RandomEngine::Graphics::Transform GetTransform();
			RandomEngine::Graphics::VertexArrayRef GetVertexArray();
			RandomEngine::Maths::Vector4f GetColor();
			
			float* GetColorPointer();

	};

}
