#include "REPCH.h"

#include "Vector3f.h"

namespace RandomEngine::Maths {

	Vector3f::Vector3f() {
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}

	Vector3f::Vector3f(const float& x, const float& y, const float& z) {
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Vector3f& Vector3f::operator+ (const Vector3f& other) {
		Vector3f result = Vector3f(x + other.x, y + other.y, z + other.z);
		return result;
	}

	Vector3f& Vector3f::operator- (const Vector3f& other) {
		Vector3f result = Vector3f(x - other.x, y - other.y, z - other.z);
		return result;
	}

	Vector3f& Vector3f::operator* (const Vector3f& other) {
		Vector3f result = Vector3f(x * other.x, y * other.y, z * other.z);
		return result;
	}

	Vector3f& Vector3f::operator/ (const Vector3f& other) {
		Vector3f result = Vector3f(x / other.x, y / other.y, z / other.z);
		return result;
	}

	Vector3f& Vector3f::operator+= (const Vector3f& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		return *this;
	}

	Vector3f& Vector3f::operator-= (const Vector3f& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		return *this;
	}

	Vector3f& Vector3f::operator*= (const Vector3f& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		return *this;
	}

	Vector3f& Vector3f::operator/= (const Vector3f& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		return *this;
	}

	Vector3f& Vector3f::operator<<= (const Vector3f& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		return *this;
	}

	bool Vector3f::operator== (const Vector3f& other) {
		return x == other.x && y == other.y && z == other.z;
	}

	bool Vector3f::operator!= (const Vector3f& other) {
		return x != other.x || y != other.y || z != other.z;
	}

	std::string Vector3f::ToString() const {
		std::stringstream ss;
		ss << this;
		return ss.str();
	}

	std::ostream& operator<<(std::ostream& stream, const Vector3f& vector) {
		stream << "Vector3f { " << vector.x << ", " << vector.y << ", " << vector.z << " }";
		return stream;
	}

}