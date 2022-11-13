#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Maths {

	struct Vector3ui : public glm::uvec3 {

		using glm::uvec3::vec;

		Vector3ui(const glm::uvec3& v) : glm::uvec3(v) { }

		inline String ToString() const {
			std::stringstream ss;
			ss << "Vector3ui { " << x << ", " << y << ", " << z << " }";
			return ss.str();
		}

		operator unsigned int* () const { return glm::value_ptr(*((glm::uvec3*)this)); }

		friend std::ostream& operator<<(std::ostream& stream, const Vector3ui& vector) {
			stream << vector.ToString();
			return stream;
		}

	};

}
