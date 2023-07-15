#include "REPCH.h"
#include "PerlinNoise.h"

#include <glm/ext.hpp>

namespace RandomEngine::Maths {

	float PerlinNoise(const Vector2f& position) {
		return glm::perlin(position);
	}

	float PerlinNoise(const Vector3f& position) {
		return glm::perlin(position);
	}

	float PerlinNoise(const Vector4f& position) {
		return glm::perlin(position);
	}

}
