#pragma once

#include "REPCH.h"

namespace RandomEngine::Maths {

	struct Vector2f {
		float x, y;

		Vector2f();
		Vector2f(const float& x, const float& y);

		Vector2f& operator+ (const Vector2f& other);
		Vector2f& operator- (const Vector2f& other);
		Vector2f& operator* (const Vector2f& other);
		Vector2f& operator/ (const Vector2f& other);
		Vector2f& operator+= (const Vector2f& other);
		Vector2f& operator-= (const Vector2f& other);
		Vector2f& operator*= (const Vector2f& other);
		Vector2f& operator/= (const Vector2f& other);
		Vector2f& operator<<= (const Vector2f& other);
		bool operator== (const Vector2f& other);
		bool operator!= (const Vector2f& other);

		std::string ToString() const;

		friend std::ostream& operator<<(std::ostream& stream, const Vector2f& vector);
	};

}