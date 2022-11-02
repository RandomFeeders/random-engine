#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Graphics/Textures/Texture2D.h"

namespace RandomEngine::Graphics {

	class VulkanTexture2D : public Texture2D {

		public:
			VulkanTexture2D(const String& path);
			VulkanTexture2D(unsigned int width, unsigned int height);
			~VulkanTexture2D();

			void Bind(unsigned int slot = 0) const override;
			void SetData(void* data, unsigned int size) override;
	};

}
