#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Textures/Texture.h"

namespace RandomEngine::Graphics {

	class Texture2D;

	using Texture2DRef = Ref<Texture2D>;

	class Texture2D : public Texture {

		public:
			Texture2D(const String& path);
			Texture2D(unsigned int width, unsigned int height);
			virtual ~Texture2D() = default;

			static Texture2DRef Create(const String& path);
			static Texture2DRef Create(unsigned int width, unsigned int height);
	};

}
