#include "REPCH.h"
#include "VulkanTexture2D.h"

namespace RandomEngine::Graphics {

	VulkanTexture2D::VulkanTexture2D(const String& path)
		: Texture2D(path) {

	}

	VulkanTexture2D::VulkanTexture2D(unsigned int width, unsigned int height)
		: Texture2D(width, height) {

	}

	VulkanTexture2D::~VulkanTexture2D() {

	}

	void VulkanTexture2D::Bind(unsigned int slot) const {

	}

	void VulkanTexture2D::SetData(void* data, unsigned int size) {

	}

}
