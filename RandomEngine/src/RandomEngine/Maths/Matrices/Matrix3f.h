#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Maths/Vectors/Vector3f.h"

namespace RandomEngine::Maths {

	struct Matrix3f : public glm::mat3 {

		using glm::mat3::mat;

		Matrix3f(const glm::mat3& m) : glm::mat3(m) { }

		inline String ToString() const {
			std::stringstream ss;
			Vector3f vecA = this->operator[](0);
			Vector3f vecB = this->operator[](1);
			Vector3f vecC = this->operator[](2);
			ss << "Matrix3f { " << vecA << ", " << vecB << ", " << vecC << " }";
			return ss.str();
		}

		operator float* () const { return glm::value_ptr(*((glm::mat3*)this)); }

		friend std::ostream& operator<<(std::ostream& stream, const Matrix3f& vector) {
			stream << vector.ToString();
			return stream;
		}

	};

}
