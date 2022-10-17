#pragma once

#include "REPCH.h"

namespace RandomEngine::Maths {

	struct Vector4f {
		float x, y, z, w;

		Vector4f() = default;
		Vector4f(const float& x, const float& y, const float& z, const float& w);

		Vector4f& operator+ (const Vector4f& other);
		Vector4f& operator- (const Vector4f& other);
		Vector4f& operator* (const Vector4f& other);
		Vector4f& operator/ (const Vector4f& other);
		Vector4f& operator+= (const Vector4f& other);
		Vector4f& operator-= (const Vector4f& other);
		Vector4f& operator*= (const Vector4f& other);
		Vector4f& operator/= (const Vector4f& other);
		Vector4f& operator<<= (const Vector4f& other);
		bool operator== (const Vector4f& other);
		bool operator!= (const Vector4f& other);

		std::string ToString() const;

		friend std::ostream& operator<<(std::ostream& stream, const Vector4f& vector);
	};

}