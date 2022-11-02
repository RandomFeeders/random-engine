#include "REPCH.h"
#include "OpenGLTexture2D.h"

#include <stb_image.h>

namespace RandomEngine::Graphics {

	OpenGLTexture2D::OpenGLTexture2D(const String& path)
		: Texture2D(path) {
		int width, height, channels;
		stbi_set_flip_vertically_on_load(1);
		stbi_uc* data = stbi_load(path.c_str(), &width, &height, &channels, 0);
		RE_CORE_ASSERT(data, "Failed to load image!");

		_width = width;
		_height = height;
		_internalFormat = GL_NONE;
		_format = GL_NONE;

		if (channels == 4) {
			_internalFormat = GL_RGBA8;
			_format = GL_RGBA;
		} else if (channels == 3) {
			_internalFormat = GL_RGB8;
			_format = GL_RGB;
		}

		RE_CORE_ASSERT(_internalFormat & _format, "Image format not supported!");

		glCreateTextures(GL_TEXTURE_2D, 1, &_rendererId);
		glTextureStorage2D(_rendererId, 1, _internalFormat, _width, _height);

		glTextureParameteri(_rendererId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(_rendererId, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(_rendererId, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(_rendererId, GL_TEXTURE_WRAP_T, GL_REPEAT);

		glTextureSubImage2D(_rendererId, 0, 0, 0, _width, _height, _format, GL_UNSIGNED_BYTE, data);

		stbi_image_free(data);
	}

	OpenGLTexture2D::OpenGLTexture2D(unsigned int width, unsigned int height)
		: Texture2D(width, height) {

		_internalFormat = GL_RGBA8;
		_format = GL_RGBA;
		
		glCreateTextures(GL_TEXTURE_2D, 1, &_rendererId);
		glTextureStorage2D(_rendererId, 1, _internalFormat, _width, _height);

		glTextureParameteri(_rendererId, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTextureParameteri(_rendererId, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glTextureParameteri(_rendererId, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTextureParameteri(_rendererId, GL_TEXTURE_WRAP_T, GL_REPEAT);
	}

	OpenGLTexture2D::~OpenGLTexture2D() {
		glDeleteTextures(1, &_rendererId);
		_rendererId = NULL;
	}

	void OpenGLTexture2D::Bind(unsigned int slot) const {
		glBindTextureUnit(slot, _rendererId);
	}

	void OpenGLTexture2D::SetData(void* data, unsigned int size) {
		unsigned int bytesPerChannel = _format == GL_RGBA ? 4 : 3;
		RE_CORE_ASSERT(size == _width * _height * bytesPerChannel, "Data must be entire texture!");
		glTextureSubImage2D(_rendererId, 0, 0, 0, _width, _height, _format, GL_UNSIGNED_BYTE, data);
	}

}
