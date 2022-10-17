#include "REPCH.h"

#include "Vector2f.h"

namespace RandomEngine::Maths {

	Vector2f::Vector2f() {
		x = 0.0f;
		y = 0.0f;
	}

	Vector2f::Vector2f(const float& x, const float& y) {
		this->x = x;
		this->y = y;
	}

	Vector2f& Vector2f::operator+ (const Vector2f& other) {
		Vector2f result = Vector2f(x + other.x, y + other.y);
		return result;
	}

	Vector2f& Vector2f::operator- (const Vector2f& other) {
		Vector2f result = Vector2f(x - other.x, y - other.y);
		return result;
	}

	Vector2f& Vector2f::operator* (const Vector2f& other) {
		Vector2f result = Vector2f(x * other.x, y * other.y);
		return result;
	}

	Vector2f& Vector2f::operator/ (const Vector2f& other) {
		Vector2f result = Vector2f(x / other.x, y / other.y);
		return result;
	}

	Vector2f& Vector2f::operator+= (const Vector2f& other) {
		x += other.x;
		y += other.y;
		return *this;
	}

	Vector2f& Vector2f::operator-= (const Vector2f& other) {
		x -= other.x;
		y -= other.y;
		return *this;
	}

	Vector2f& Vector2f::operator*= (const Vector2f& other) {
		x *= other.x;
		y *= other.y;
		return *this;
	}

	Vector2f& Vector2f::operator/= (const Vector2f& other) {
		x /= other.x;
		y /= other.y;
		return *this;
	}

	Vector2f& Vector2f::operator<<= (const Vector2f& other) {
		x = other.x;
		y = other.y;
		return *this;
	}

	bool Vector2f::operator== (const Vector2f& other) {
		return x == other.x && y == other.y;
	}

	bool Vector2f::operator!= (const Vector2f& other) {
		return x != other.x || y != other.y;
	}

	std::string Vector2f::ToString() const {
		std::stringstream ss;
		ss << this;
		return ss.str();
	}

	std::ostream& operator<<(std::ostream& stream, const Vector2f& vector) {
		stream << "Vector2f { " << vector.x << ", " << vector.y << " }";
		return stream;
	}	

}