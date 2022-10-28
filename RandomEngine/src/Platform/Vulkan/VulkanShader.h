#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Shader.h"

namespace RandomEngine::Graphics {

	class VulkanShader : public Shader {

	private:
		unsigned int _rendererId;

	public:
		VulkanShader(const String& vertexSrc, const String& fragmentSrc);

		void Bind() const override;
		void Unbind() const override;

		// void Define(const String& name, int value);
		// void Define(const String& name, float value);
		// void Define(const String& name, const Maths::Vector2f& value);
		// void Define(const String& name, const Maths::Vector3f& value);
		// void Define(const String& name, const Maths::Vector4f& value);
		// void Define(const String& name, const Maths::Matrix4f& value);
	};

}
