#include "REPCH.h"
#include "Shader.h"

#include "RandomEngine/IO/File.h"
#include "RandomEngine/Graphics/Renderer/RendererAPI.h"
#include "Platform/OpenGL/OpenGLShader.h"
#include "Platform/Vulkan/VulkanShader.h"

namespace RandomEngine::Graphics {

	Shader::Dictionary Shader::PreProcessFile(const String& source, MapperFunc mapper) {
		Shader::Dictionary shaderSources;

		const char* typeToken = "#type";
		size_t typeTokenLength = strlen(typeToken);
		size_t pos = source.find(typeToken, 0);

		while (pos != String::npos) {
			size_t eol = source.find_first_of("\r\n", pos);
			RE_CORE_ASSERT(eol != String::npos, "Shader syntax error!");
			size_t begin = pos + typeTokenLength + 1;
			String type = source.substr(begin, eol - begin);
			RE_CORE_ASSERT(mapper(type), "Invalid shader type specified!");

			size_t nextLinePos = source.find_first_not_of("\r\n", eol);
			pos = source.find(typeToken, nextLinePos);			

			shaderSources[mapper(type)] = (pos == String::npos) ? source.substr(nextLinePos) : source.substr(nextLinePos, pos - nextLinePos);
		}

		return shaderSources;
	}

	ShaderRef Shader::Create(const String& name, const String& vertexSrc, const String& fragmentSrc) {
		ShaderRef shader;

		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				shader = CreateRef<OpenGLShader>(vertexSrc, fragmentSrc);
				break;
			case RendererAPI::API::Vulkan:
				shader = CreateRef<VulkanShader>(vertexSrc, fragmentSrc);
				break;
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}

		shader->_name = name;
		return shader;
	}

	ShaderRef Shader::Create(const String& filePath, const String& name) {
		IO::File file(filePath, IO::File::Mode::Open, IO::File::Access::Read);
		if (!file.Read()) return nullptr;

		Shader::Dictionary dict;
		ShaderRef shader;

		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				dict = PreProcessFile(file.GetContent(), OpenGLShader::GetMapper());
				shader = CreateRef<OpenGLShader>(dict);
				break;
			case RendererAPI::API::Vulkan:
				dict = PreProcessFile(file.GetContent(), VulkanShader::GetMapper());
				shader = CreateRef<VulkanShader>(dict);
				break;
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}

		if (name == "") {
			auto lastSlash = filePath.find_last_of("/\\");
			lastSlash = lastSlash == String::npos ? 0 : lastSlash + 1;
			auto lastDot = filePath.rfind('.');
			auto count = lastDot == String::npos ? filePath.size() - lastSlash : lastDot - lastSlash;

			shader->_name = filePath.substr(lastSlash, count);
		} else {
			shader->_name = name;
		}

		return shader;
	}

}
