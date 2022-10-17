#pragma once

#include "REPCH.h"

#include <glm/glm.hpp>

namespace RandomEngine::Maths {

	struct Vector3f : public glm::vec3 {

		using glm::vec3::vec;

		Vector3f(const glm::vec3& v) : glm::vec3(v) { }

		inline std::string ToString() const {
			std::stringstream ss;
			ss << "Vector3f { " << x << ", " << y << ", " << z << " }";
			return ss.str();
		}

		friend std::ostream& operator<<(std::ostream& stream, const Vector3f& vector) {
			stream << vector.ToString();
			return stream;
		}
		
	};

}