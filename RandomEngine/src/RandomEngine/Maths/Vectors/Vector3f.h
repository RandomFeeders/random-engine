#pragma once

#include "REPCH.h"

namespace RandomEngine::Maths {

	struct Vector3f {
		float x, y, z;

		Vector3f();
		Vector3f(const float& x, const float& y, const float& z);

		Vector3f& operator+ (const Vector3f& other);
		Vector3f& operator- (const Vector3f& other);
		Vector3f& operator* (const Vector3f& other);
		Vector3f& operator/ (const Vector3f& other);
		Vector3f& operator+= (const Vector3f& other);
		Vector3f& operator-= (const Vector3f& other);
		Vector3f& operator*= (const Vector3f& other);
		Vector3f& operator/= (const Vector3f& other);
		Vector3f& operator<<= (const Vector3f& other);
		bool operator== (const Vector3f& other);
		bool operator!= (const Vector3f& other);

		std::string ToString() const;

		friend std::ostream& operator<<(std::ostream& stream, const Vector3f& vector);
	};

}