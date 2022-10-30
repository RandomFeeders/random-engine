#include "REPCH.h"
#include "OpenGLTexture2D.h"

#include <glad/glad.h>
#include <stb_image.h>

namespace RandomEngine::Graphics {

	OpenGLTexture2D::OpenGLTexture2D(const String& path)
		: Texture2D(path) {
		int width, height, channels;
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		RE_CORE_ASSERT(data, "Failed to load image!");

		_width = width;
		_height = height;

		glCreateTextures(GL_TEXTURE_2D, 1, &_rendererId);
		glTextureStorage2D(_rendererId, 1, GL_RGB8, _width, _height);
		glTextureParameteri(_rendererId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(_rendererId, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTextureSubImage2D(_rendererId, 0, 0, 0, _width, _height, GL_RGB, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data);
	}

	OpenGLTexture2D::~OpenGLTexture2D() {
		glDeleteTextures(1, &_rendererId);
		_rendererId = NULL;
	}

	void OpenGLTexture2D::Bind(unsigned int slot) const {
		glBindTextureUnit(slot, _rendererId);
	}

}
