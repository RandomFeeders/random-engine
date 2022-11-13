#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>

#include "RandomEngine/Core/Types.h"

namespace RandomEngine::Maths {

	struct Vector4i : public glm::ivec4 {

		using glm::ivec4::vec;

		Vector4i(const glm::ivec4& v) : glm::ivec4(v) { }

		inline String ToString() const {
			std::stringstream ss;
			ss << "Vector4i { " << x << ", " << y << ", " << z << ", " << w << " }";
			return ss.str();
		}

		operator int* () const { return glm::value_ptr(*((glm::ivec4*)this)); }

		friend std::ostream& operator<<(std::ostream& stream, const Vector4i& vector) {
			stream << vector.ToString();
			return stream;
		}

	};

}
