#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Maths {

	struct Vector2f : public glm::vec2 {

		using glm::vec2::vec;

		Vector2f(const glm::vec2& v) : glm::vec2(v) { }

		inline String ToString() const {
			std::stringstream ss;
			ss << "Vector2f { " << x << ", " << y << " }";
			return ss.str();
		}

		operator float* () const { return glm::value_ptr(*((glm::vec2*)this)); }

		friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vector) {
			stream << vector.ToString();
			return stream;
		}

	};

}
