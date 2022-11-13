#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Maths {

	struct Vector3i : public glm::ivec3 {

		using glm::ivec3::vec;

		Vector3i(const glm::ivec3& v) : glm::ivec3(v) { }

		inline String ToString() const {
			std::stringstream ss;
			ss << "Vector3i { " << x << ", " << y << ", " << z << " }";
			return ss.str();
		}

		operator int* () const { return glm::value_ptr(*((glm::ivec3*)this)); }

		friend std::ostream& operator<<(std::ostream& stream, const Vector3i& vector) {
			stream << vector.ToString();
			return stream;
		}

	};

}
