#pragma once

#include <glad/glad.h>

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Textures/Texture2D.h"

namespace RandomEngine::Graphics {

	class OpenGLTexture2D : public Texture2D {

		private:
			unsigned int _rendererId;
			GLenum _internalFormat, _format;

		public:
			OpenGLTexture2D(const String& path);
			OpenGLTexture2D(unsigned int width, unsigned int height);
			~OpenGLTexture2D();

			void Bind(unsigned int slot = 0) const override;
			void SetData(void* data, unsigned int size) override;
	};

}
