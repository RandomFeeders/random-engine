#pragma once

#include <iostream>
#include <sstream>
#include <glm/glm.hpp>

#include "RandomEngine/Maths/Vectors/Vector4f.h"

namespace RandomEngine::Maths {

	struct Matrix4f : public glm::mat4 {

		using glm::mat4::mat;

		Matrix4f(const glm::mat4& m) : glm::mat4(m) { }

		inline std::string ToString() const {
			std::stringstream ss;
			Vector4f vecA = this->operator[](0);
			Vector4f vecB = this->operator[](1);
			Vector4f vecC = this->operator[](2);
			Vector4f vecD = this->operator[](3);
			ss << "Matrix4f { " << vecA << ", " << vecB << ", " << vecC << ", " << vecD << " }";
			return ss.str();
		}

		friend std::ostream& operator<<(std::ostream& stream, const Matrix4f& vector) {
			stream << vector.ToString();
			return stream;
		}
		
	};

}
