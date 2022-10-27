#pragma once

#include "RandomEngine/Maths/Maths.h"
#include "Transform.h"

namespace RandomEngine::Graphics {

	class GameObject {

		public:
			Transform Transform;

			GameObject(Graphics::Transform transform) : Transform(transform) { }
	};

}
