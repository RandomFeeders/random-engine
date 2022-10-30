#include "REPCH.h"
#include "VulkanShader.h"

namespace RandomEngine::Graphics {

	static unsigned int Mapper(const String& type) { return 0; }

	Shader::MapperFunc VulkanShader::GetMapper() { return Mapper; }

	VulkanShader::VulkanShader(Shader::Dictionary shaderDict) { }

	VulkanShader::VulkanShader(const String& vertexSrc, const String& fragmentSrc) { }

	void VulkanShader::Bind() const { }

	void VulkanShader::Unbind() const { }

}
