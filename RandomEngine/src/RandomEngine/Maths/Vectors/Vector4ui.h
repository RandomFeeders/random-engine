#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Maths {

	struct Vector4ui : public glm::uvec4 {

		using glm::uvec4::vec;

		Vector4ui(const glm::uvec4& v) : glm::uvec4(v) { }

		inline String ToString() const {
			std::stringstream ss;
			ss << "Vector4ui { " << x << ", " << y << ", " << z << ", " << w << " }";
			return ss.str();
		}

		operator unsigned int* () const { return glm::value_ptr(*((glm::uvec4*)this)); }

		friend std::ostream& operator<<(std::ostream& stream, const Vector4ui& vector) {
			stream << vector.ToString();
			return stream;
		}

	};

}
