#include "REPCH.h"

#include "Vector4f.h"

namespace RandomEngine::Maths {

	Vector4f::Vector4f(const float& x, const float& y, const float& z, const float& w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;
	}

	Vector4f& Vector4f::operator+ (const Vector4f& other) {
		Vector4f result = Vector4f(x + other.x, y + other.y, z + other.z, w + other.w);
		return result;
	}

	Vector4f& Vector4f::operator- (const Vector4f& other) {
		Vector4f result = Vector4f(x - other.x, y - other.y, z - other.z, w - other.w);
		return result;
	}

	Vector4f& Vector4f::operator* (const Vector4f& other) {
		Vector4f result = Vector4f(x * other.x, y * other.y, z * other.z, w * other.w);
		return result;
	}

	Vector4f& Vector4f::operator/ (const Vector4f& other) {
		Vector4f result = Vector4f(x / other.x, y / other.y, z / other.z, w / other.w);
		return result;
	}

	Vector4f& Vector4f::operator+= (const Vector4f& other) {
		x += other.x;
		y += other.y;
		z += other.z;
		w += other.w;
		return *this;
	}

	Vector4f& Vector4f::operator-= (const Vector4f& other) {
		x -= other.x;
		y -= other.y;
		z -= other.z;
		w -= other.w;
		return *this;
	}

	Vector4f& Vector4f::operator*= (const Vector4f& other) {
		x *= other.x;
		y *= other.y;
		z *= other.z;
		w *= other.w;
		return *this;
	}

	Vector4f& Vector4f::operator/= (const Vector4f& other) {
		x /= other.x;
		y /= other.y;
		z /= other.z;
		w /= other.w;
		return *this;
	}

	Vector4f& Vector4f::operator<<= (const Vector4f& other) {
		x = other.x;
		y = other.y;
		z = other.z;
		w = other.w;
		return *this;
	}

	bool Vector4f::operator== (const Vector4f& other) {
		return x == other.x && y == other.y && z == other.z && w == other.w;
	}

	bool Vector4f::operator!= (const Vector4f& other) {
		return x != other.x || y != other.y || z != other.z || w != other.w;
	}

	std::string Vector4f::ToString() const {
		std::stringstream ss;
		ss << this;
		return ss.str();
	}

	std::ostream& operator<<(std::ostream& stream, const Vector4f& vector) {
		stream << "Vector4f { " << vector.x << ", " << vector.y << ", " << vector.z << ", " << vector.w << " }";
		return stream;
	}

}