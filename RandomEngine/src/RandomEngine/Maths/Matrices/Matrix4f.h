#pragma once

#include <iostream>
#include <sstream>
#include <glm/ext.hpp>

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Maths/Vectors/Vector3f.h"
#include "RandomEngine/Maths/Vectors/Vector4f.h"

namespace RandomEngine::Maths {

	struct Matrix4f : public glm::mat4 {

		using glm::mat4::mat;

		Matrix4f(const glm::mat4& m) : glm::mat4(m) { }

		inline String ToString() const {
			std::stringstream ss;
			Vector4f vecA = this->operator[](0);
			Vector4f vecB = this->operator[](1);
			Vector4f vecC = this->operator[](2);
			Vector4f vecD = this->operator[](3);
			ss << "Matrix4f { " << vecA << ", " << vecB << ", " << vecC << ", " << vecD << " }";
			return ss.str();
		}

		operator float* () const { return glm::value_ptr(*((glm::mat4*)this)); }

		friend std::ostream& operator<<(std::ostream& stream, const Matrix4f& vector) {
			stream << vector.ToString();
			return stream;
		}

		// Identity matrix
		static Matrix4f Identity();

		// Projection matrices
		static Matrix4f Orthographic(float top, float right, float bottom, float left, float near_, float far_);
		static Matrix4f Perspective(float fov, float aspectRatio, float near_, float far_);

		// Translation matrices
		static Matrix4f Translation(const Vector3f& translation);
		static Matrix4f Rotation(float angle, const Vector3f& axis);
		static Matrix4f Scale(const Vector3f& scale);

		// Utils
		static const Matrix4f& Inverse(const Matrix4f& matrix);		
	};

}
