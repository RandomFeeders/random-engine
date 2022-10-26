#include "REPCH.h"

#include "Shader.h"

#include <glad/glad.h>

namespace RandomEngine::Graphics {

	Shader::Shader(const std::string& vertexSrc, const std::string& fragmentSrc) 
		: _rendererId(NULL) {
		unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);

		const char* source = vertexSrc.c_str();
		glShaderSource(vertexShader, 1, &source, 0);

		glCompileShader(vertexShader);

		int status = 0;
		glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) {
			int maxLength = 0;
			glGetShaderiv(vertexShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(vertexShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(vertexShader);

			RE_CORE_ERROR("{0}", infoLog.data());
			RE_CORE_ASSERT(false, "Vertex shader compilation failure!");

			return;
		}

		unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);

		source = fragmentSrc.c_str();
		glShaderSource(fragmentShader, 1, &source, 0);

		glCompileShader(fragmentShader);

		status = 0;
		glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) {
			int maxLength = 0;
			glGetShaderiv(fragmentShader, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetShaderInfoLog(fragmentShader, maxLength, &maxLength, &infoLog[0]);

			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			RE_CORE_ERROR("{0}", infoLog.data());
			RE_CORE_ASSERT(false, "Fragment shader compilation failure!");

			return;
		}

		_rendererId = glCreateProgram();

		glAttachShader(_rendererId, vertexShader);
		glAttachShader(_rendererId, fragmentShader);

		glLinkProgram(_rendererId);

		status = 0;
		glGetProgramiv(_rendererId, GL_LINK_STATUS, &status);
		if (status == GL_FALSE) {
			int maxLength = 0;
			glGetProgramiv(_rendererId, GL_INFO_LOG_LENGTH, &maxLength);

			std::vector<char> infoLog(maxLength);
			glGetProgramInfoLog(_rendererId, maxLength, &maxLength, &infoLog[0]);

			glDeleteProgram(_rendererId);
			glDeleteShader(vertexShader);
			glDeleteShader(fragmentShader);

			RE_CORE_ERROR("{0}", infoLog.data());
			RE_CORE_ASSERT(false, "Shader linker failure!");

			return;
		}

		glDetachShader(_rendererId, vertexShader);
		glDetachShader(_rendererId, fragmentShader);
		glDeleteShader(vertexShader);
		glDeleteShader(fragmentShader);
	}

	Shader::~Shader() {
		glDeleteProgram(_rendererId);
	}

	void Shader::Bind() const {
		glUseProgram(_rendererId);
	}

	void Shader::Unbind() const {
		glUseProgram(NULL);
	}

	void Shader::Define(const std::string& name, int value) {
		glUniform1i(glGetUniformLocation(_rendererId, name.c_str()), value);
	}

	void Shader::Define(const std::string& name, float value) {
		glUniform1f(glGetUniformLocation(_rendererId, name.c_str()), value);
	}

	void Shader::Define(const std::string& name, const Maths::Vector2f& value) {
		glUniform2f(glGetUniformLocation(_rendererId, name.c_str()), value.x, value.y);
	}

	void Shader::Define(const std::string& name, const Maths::Vector3f& value) {
		glUniform3f(glGetUniformLocation(_rendererId, name.c_str()), value.x, value.y, value.z);
	}

	void Shader::Define(const std::string& name, const Maths::Vector4f& value) {
		glUniform4f(glGetUniformLocation(_rendererId, name.c_str()), value.x, value.y, value.z, value.w);
	}

	void Shader::Define(const std::string& name, const Maths::Matrix4f& value) {
		glUniformMatrix4fv(glGetUniformLocation(_rendererId, name.c_str()), 1, GL_FALSE, value);
	}

}
