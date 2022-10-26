#pragma once

#include <iostream>
#include <sstream>
#include <glm/glm.hpp>

namespace RandomEngine::Maths {

	struct Vector2f : public glm::vec2 {

		using glm::vec2::vec;

		Vector2f(const glm::vec2& v) : glm::vec2(v) { }

		inline std::string ToString() const {
			std::stringstream ss;
			ss << "Vector2f { " << x << ", " << y << " }";
			return ss.str();
		}

		friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vector) {
			stream << vector.ToString();
			return stream;
		}

	};

}
