#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>

namespace RandomEngine::Maths {

	struct Vector4f : public glm::vec4 {

		using glm::vec4::vec;

		Vector4f(const glm::vec4& v) : glm::vec4(v) { }

		inline std::string ToString() const {
			std::stringstream ss;
			ss << "Vector4f { " << x << ", " << y << ", " << z << ", " << w << " }";
			return ss.str();
		}

		operator float* () const { return glm::value_ptr(*((glm::vec4*)this)); }

		friend std::ostream& operator<<(std::ostream& stream, const Vector4f& vector) {
			stream << vector.ToString();
			return stream;
		}

	};

}
