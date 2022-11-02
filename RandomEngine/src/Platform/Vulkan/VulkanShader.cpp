#include "REPCH.h"
#include "VulkanShader.h"

namespace RandomEngine::Graphics {

	static unsigned int Mapper(const String& type) { return 0; }

	Shader::MapperFunc VulkanShader::GetMapper() { return Mapper; }

	VulkanShader::VulkanShader(Shader::Dictionary shaderDict) { }

	VulkanShader::VulkanShader(const String& vertexSrc, const String& fragmentSrc) { }

	void VulkanShader::Bind() const { }

	void VulkanShader::Unbind() const { }

	void VulkanShader::Define(const String& name, int value) { }

	void VulkanShader::Define(const String& name, float value) { }

	void VulkanShader::Define(const String& name, const Maths::Vector2f& value) { }

	void VulkanShader::Define(const String& name, const Maths::Vector3f& value) { }

	void VulkanShader::Define(const String& name, const Maths::Vector4f& value) { }

	void VulkanShader::Define(const String& name, const Maths::Matrix3f& value) { }

	void VulkanShader::Define(const String& name, const Maths::Matrix4f& value) { }

}
