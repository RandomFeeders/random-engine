#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Shader/Shader.h"
#include "RandomEngine/Maths/Maths.h"

namespace RandomEngine::Graphics {

	class OpenGLShader : public Shader {
		friend class Shader;

		private:
			unsigned int _rendererId;

			void Compile(Shader::Dictionary sources);

			static MapperFunc GetMapper();

		public:
			OpenGLShader(const String& vertexSrc, const String& fragmentSrc);
			OpenGLShader(Shader::Dictionary shaderDict);
			virtual ~OpenGLShader();

			void Bind() const override;
			void Unbind() const override;

			void Define(const String& name, int value) override;
			void Define(const String& name, float value) override;
			void Define(const String& name, const Maths::Vector2f& value) override;
			void Define(const String& name, const Maths::Vector3f& value) override;
			void Define(const String& name, const Maths::Vector4f& value) override;
			void Define(const String& name, const Maths::Matrix3f& value) override;
			void Define(const String& name, const Maths::Matrix4f& value) override;
	};

}
