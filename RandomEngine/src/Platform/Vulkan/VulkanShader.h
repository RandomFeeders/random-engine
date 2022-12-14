#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Shader/Shader.h"
#include "RandomEngine/Maths/Maths.h"

namespace RandomEngine::Graphics {

	class VulkanShader : public Shader {
		friend class Shader;

		private:
			unsigned int _rendererId;

			static MapperFunc GetMapper();

		public:
			VulkanShader(const String& vertexSrc, const String& fragmentSrc);
			VulkanShader(Shader::Dictionary shaderDict);

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
