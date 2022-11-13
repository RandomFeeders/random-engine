#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Maths {

	struct Vector2i : public glm::ivec2 {

		using glm::ivec2::vec;

		Vector2i(const glm::ivec2& v) : glm::ivec2(v) { }

		inline String ToString() const {
			std::stringstream ss;
			ss << "Vector2ui { " << x << ", " << y << " }";
			return ss.str();
		}

		operator int* () const { return glm::value_ptr(*((glm::ivec2*)this)); }

		friend std::ostream& operator<<(std::ostream& stream, const Vector2i& vector) {
			stream << vector.ToString();
			return stream;
		}

	};

}
