#include "REPCH.h"
#include "OpenGLShader.h"

#include <glad/glad.h>

namespace RandomEngine::Graphics {

	static GLenum Mapper(const String& type) {
		if (type == "vertex")
			return GL_VERTEX_SHADER;
		else if (type == "fragment" || type == "pixel")
			return GL_FRAGMENT_SHADER;

		RE_CORE_ASSERT(false, "Invalid shader type specified!");
		return GL_NONE;
	}

	Shader::MapperFunc OpenGLShader::GetMapper() { return Mapper; }

	OpenGLShader::OpenGLShader(Shader::Dictionary shaderDict)
		: _rendererId(NULL) {
		Compile(shaderDict);
	}

	OpenGLShader::OpenGLShader(const String& vertexSrc, const String& fragmentSrc)
		: _rendererId(NULL) {
		Shader::Dictionary dict;
		dict[GL_VERTEX_SHADER] = vertexSrc;
		dict[GL_FRAGMENT_SHADER] = fragmentSrc;
		Compile(dict);
	}

	OpenGLShader::~OpenGLShader() {
		glDeleteProgram(_rendererId);
	}

	void OpenGLShader::Compile(Shader::Dictionary sources) {
		RE_CORE_ASSERT(sources.size() <= 2, "Only two shaders per file is supported!");
		Array<unsigned int, 2> shaderList { };
		
		int index = 0;
		for (auto& item : sources) {
			GLenum type = item.first;
			const String& source = item.second;

			unsigned int shader = glCreateShader(type);

			const char* c_source = source.c_str();
			glShaderSource(shader, 1, &c_source, 0);

			glCompileShader(shader);

			int status = 0;
			glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
			if (status == GL_FALSE) {
				int maxLength = 0;
				glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &maxLength);

				List<char> infoLog(maxLength);
				glGetShaderInfoLog(shader, maxLength, &maxLength, &infoLog[0]);

				glDeleteShader(shader);

				RE_CORE_ERROR("{0}", infoLog.data());
				RE_CORE_ASSERT(false, "Shader compilation failure!");

				return;
			}

			shaderList[index++] = shader;
		}

		_rendererId = glCreateProgram();

		for (auto shader : shaderList) {
			glAttachShader(_rendererId, shader);
		}

		glLinkProgram(_rendererId);

		int status = 0;
		glGetProgramiv(_rendererId, GL_LINK_STATUS, &status);
		if (status == GL_FALSE) {
			int maxLength = 0;
			glGetProgramiv(_rendererId, GL_INFO_LOG_LENGTH, &maxLength);

			List<char> infoLog(maxLength);
			glGetProgramInfoLog(_rendererId, maxLength, &maxLength, &infoLog[0]);

			glDeleteProgram(_rendererId);
			
			for (auto shader : shaderList) {
				glDeleteShader(shader);
			}

			RE_CORE_ERROR("{0}", infoLog.data());
			RE_CORE_ASSERT(false, "Shader linker failure!");

			_rendererId = NULL;

			return;
		}

		for (auto shader : shaderList) {
			glDetachShader(_rendererId, shader);
			glDeleteShader(shader);
		}
	}

	void OpenGLShader::Bind() const {
		glUseProgram(_rendererId);
	}

	void OpenGLShader::Unbind() const {
		glUseProgram(NULL);
	}

	void OpenGLShader::Define(const String& name, int value) {
		glUniform1i(glGetUniformLocation(_rendererId, name.c_str()), value);
	}

	void OpenGLShader::Define(const String& name, float value) {
		glUniform1f(glGetUniformLocation(_rendererId, name.c_str()), value);
	}

	void OpenGLShader::Define(const String& name, const Maths::Vector2f& value) {
		glUniform2f(glGetUniformLocation(_rendererId, name.c_str()), value.x, value.y);
	}

	void OpenGLShader::Define(const String& name, const Maths::Vector3f& value) {
		glUniform3f(glGetUniformLocation(_rendererId, name.c_str()), value.x, value.y, value.z);
	}

	void OpenGLShader::Define(const String& name, const Maths::Vector4f& value) {
		glUniform4f(glGetUniformLocation(_rendererId, name.c_str()), value.x, value.y, value.z, value.w);
	}

	void OpenGLShader::Define(const String& name, const Maths::Matrix3f& value) {
		glUniformMatrix3fv(glGetUniformLocation(_rendererId, name.c_str()), 1, GL_FALSE, value);
	}

	void OpenGLShader::Define(const String& name, const Maths::Matrix4f& value) {
		glUniformMatrix4fv(glGetUniformLocation(_rendererId, name.c_str()), 1, GL_FALSE, value);
	}

}
