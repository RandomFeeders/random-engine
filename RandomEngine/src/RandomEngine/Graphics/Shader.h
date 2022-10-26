#pragma once

#include <string>
#include "RandomEngine/Maths/Maths.h"

namespace RandomEngine::Graphics {

	class Shader {

		private:
			unsigned int _rendererId;

		public:
			Shader(const std::string& vertexSrc, const std::string& fragmentSrc);
			~Shader();

			void Bind() const;
			void Unbind() const;

			void Define(const std::string& name, int value);
			void Define(const std::string& name, float value);
			void Define(const std::string& name, const Maths::Vector2f& value);
			void Define(const std::string& name, const Maths::Vector3f& value);
			void Define(const std::string& name, const Maths::Vector4f& value);
			void Define(const std::string& name, const Maths::Matrix4f& value);
	};

}
