#pragma once

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Graphics {

	class Texture {

		protected:
			unsigned int _width;
			unsigned int _height;

		public:
			Texture(const String& path) : _width(0), _height(0) { };
			virtual ~Texture() = default;
			
			virtual void Bind(unsigned int slot = 0) const = 0;

			virtual inline unsigned int GetWidth() const { return _width; }
			virtual inline unsigned int GetHeight() const { return _height; }
	};

}
