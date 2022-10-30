#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Textures/Texture2D.h"

namespace RandomEngine::Graphics {

	class OpenGLTexture2D : public Texture2D {

		private:
			unsigned int _rendererId;

		public:
			OpenGLTexture2D(const String& path);
			~OpenGLTexture2D();

			void Bind(unsigned int slot = 0) const override;
	};

}
