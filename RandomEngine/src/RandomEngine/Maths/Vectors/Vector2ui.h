#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Maths {

	struct Vector2ui : public glm::uvec2 {

		using glm::uvec2::vec;

		Vector2ui(const glm::uvec2& v) : glm::uvec2(v) { }

		inline String ToString() const {
			std::stringstream ss;
			ss << "Vector2ui { " << x << ", " << y << " }";
			return ss.str();
		}

		operator unsigned int* () const { return glm::value_ptr(*((glm::uvec2*)this)); }

		friend std::ostream& operator<<(std::ostream& stream, const Vector2ui& vector) {
			stream << vector.ToString();
			return stream;
		}

	};

}
