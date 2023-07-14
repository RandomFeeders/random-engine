#pragma once

#include <glm/ext.hpp>

#include "RandomEngine/Maths/Vectors/Vector2f.h"
#include "RandomEngine/Maths/Vectors/Vector3f.h"
#include "RandomEngine/Maths/Vectors/Vector4f.h"

namespace RandomEngine::Maths {

	float PerlinNoise(const Vector2f& position);
	float PerlinNoise(const Vector3f& position);
	float PerlinNoise(const Vector4f& position);

}
