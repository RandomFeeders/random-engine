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

			shaderSources[mapper(type)] =
				source.substr(
					nextLinePos,
					pos - (nextLinePos == String::npos ? source.size() - 1 : nextLinePos)
				);
		}

		return shaderSources;
	}

	ShaderRef Shader::Create(const String& name, const String& vertexSrc, const String& fragmentSrc) {
		Shader* shader;

		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				shader = new OpenGLShader(vertexSrc, fragmentSrc);
				break;
			case RendererAPI::API::Vulkan:
				shader = new VulkanShader(vertexSrc, fragmentSrc);
				break;
			default:
				RE_CORE_ASSERT(false, "Renderer API selected not supported!");
				return nullptr;
		}

		shader->_name = name;
		return ShaderRef(shader);
	}

	ShaderRef Shader::Create(const String& filePath, const String& name) {
		IO::File file(filePath);
		Shader::Dictionary dict;
		Shader* shader;

		switch (RendererAPI::GetAPI()) {
			case RendererAPI::API::OpenGL:
				dict = PreProcessFile(file.Read(), OpenGLShader::GetMapper());
				shader = new OpenGLShader(dict);
				break;
			case RendererAPI::API::Vulkan:
				dict = PreProcessFile(file.Read(), VulkanShader::GetMapper());
				shader = new VulkanShader(dict);
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

		return ShaderRef(shader);
	}

}
