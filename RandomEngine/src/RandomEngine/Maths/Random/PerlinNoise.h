#pragma once

#include <glm/ext.hpp>

#include "RandomEngine/Maths/Vectors/Vector2f.h"
#include "RandomEngine/Maths/Vectors/Vector2i.h"
#include "RandomEngine/Maths/Vectors/Vector2ui.h"
#include "RandomEngine/Maths/Vectors/Vector3f.h"
#include "RandomEngine/Maths/Vectors/Vector3i.h"
#include "RandomEngine/Maths/Vectors/Vector3ui.h"
#include "RandomEngine/Maths/Vectors/Vector4f.h"
#include "RandomEngine/Maths/Vectors/Vector4i.h"
#include "RandomEngine/Maths/Vectors/Vector4ui.h"

namespace RandomEngine::Maths {

	float PerlinNoise(const Vector2f& position);
	float PerlinNoise(const Vector3f& position);
	float PerlinNoise(const Vector4f& position);

}
