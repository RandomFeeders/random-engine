#include "REPCH.h"
#include "Matrix4f.h"

namespace RandomEngine::Maths {

	Matrix4f::Matrix4f() {
		for (int i = 0; i < 4 * 4; i++) {
			elements[i] = 0.0f;
		}
	}

	Matrix4f::Matrix4f(float diagonal) {
		for (int i = 0; i < 4 * 4; i++) {
			elements[i] = 0.0f;
		}

		elements[0 + 0 * 4] = diagonal;
		elements[1 + 1 * 4] = diagonal;
		elements[2 + 2 * 4] = diagonal;
		elements[3 + 3 * 4] = diagonal;
	}

	Matrix4f& Matrix4f::operator* (const Matrix4f& other) {
		Matrix4f result = Matrix4f();

		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				float sum = 0;
				for (int e = 0; e < 4; e++) {
					sum += elements[x + e * 4] * other.elements[y + e * 4];
				}
				result.elements[x + y * 4] = sum;
			}
		}

		return result;
	}

	Matrix4f& Matrix4f::operator*= (const Matrix4f& other) {
		for (int y = 0; y < 4; y++) {
			for (int x = 0; x < 4; x++) {
				float sum = 0;
				for (int e = 0; e < 4; e++) {
					sum += elements[x + e * 4] * other.elements[y + e * 4];
				}
				elements[x + y * 4] = sum;
			}
		}
		return *this;
	}

	Matrix4f Matrix4f::identity() {
		return Matrix4f(1.0f);
	}

	Matrix4f Matrix4f::orthographic(float top, float right, float bottom, float left, float _near, float _far) {

		// |  2 / (r - l)        0              0          -((r + l) / (r - l))  |
		// |      0          2 / (t - b)        0          -((t + b) / (t - b))  |
		// |      0              0         -2 / (f - n)    -((f + n) / (f - n))  |
		// |      0              0              0                    1           |

		Matrix4f result(1.0f);

		result.elements[0 + 0 * 4] = 2.0f / (right - left);
		result.elements[1 + 1 * 4] = 2.0f / (top - bottom);
		result.elements[2 + 2 * 4] = -2.0f / (_far - _near);

		result.elements[0 + 3 * 4] = -((right + left) / (right - left));
		result.elements[1 + 3 * 4] = -((top + bottom) / (top - bottom));
		result.elements[2 + 3 * 4] = -((_far + _near) / (_far - _near));

		return result;
	}

	Matrix4f Matrix4f::perspective(float fov, float aspectRatio, float _near, float _far) {

		// |  1 / (ar * tan(a / 2))          0                     0                         0             |
		// |           0               1 / tan(a / 2)              0                         0             |
		// |           0                     0           -((f + n) / (f - n))    -((2 * f * n) / (f - n))  |
		// |           0                     0                    -1                         0             |

		Matrix4f result(0.0f);

		float k = 1 / tan(TO_RADIANS(fov / 2));
		float arm1 = 1.0f / aspectRatio;

		result.elements[0 + 0 * 4] = k * arm1;
		result.elements[1 + 1 * 4] = k;
		result.elements[2 + 2 * 4] = -((_far + _near) / (_far - _near));
		result.elements[3 + 2 * 4] = -1.0f;
		result.elements[2 + 3 * 4] = -((2.0f * _near * _far) / (_far - _near));

		return result;
	}

	Matrix4f Matrix4f::translation(const Vector3f& translation) {
		Matrix4f result(1.0f);

		result.elements[0 + 3 * 4] = translation.x;
		result.elements[1 + 3 * 4] = translation.y;
		result.elements[2 + 3 * 4] = translation.z;

		return result;
	}

	Matrix4f Matrix4f::rotation(float angle, const Vector3f& axis) {

		// |  (1 - c)xx + c    (1 - c)yx - sz   (1 - c)zx + sy   0  |
		// |  (1 - c)xy + sz   (1 - c)yy + c    (1 - c)zy - sx   0  |
		// |  (1 - c)xz - sy   (1 - c)yz + sx   (1 - c)zz + c    0  |
		// |        0                 0                0         1  |

		Matrix4f result(1.0f);

		float r = TO_RADIANS(angle);
		float c = cos(r);
		float s = sin(r);
		float omc = 1 - c;

		result.elements[0 + 0 * 4] = (axis.x * axis.x * omc) + (c);
		result.elements[1 + 0 * 4] = (axis.x * axis.y * omc) + (s * axis.z);
		result.elements[2 + 0 * 4] = (axis.x * axis.z * omc) - (s * axis.y);

		result.elements[0 + 1 * 4] = (axis.y * axis.x * omc) - (s * axis.z);
		result.elements[1 + 1 * 4] = (axis.y * axis.y * omc) + (c);
		result.elements[2 + 1 * 4] = (axis.y * axis.z * omc) + (s * axis.x);

		result.elements[0 + 2 * 4] = (axis.z * axis.x * omc) + (s * axis.y);
		result.elements[1 + 2 * 4] = (axis.z * axis.y * omc) - (s * axis.x);
		result.elements[2 + 2 * 4] = (axis.z * axis.z * omc) + (c);

		return result;
	}

	Matrix4f Matrix4f::scale(const Vector3f& scale) {
		Matrix4f result(1.0f);

		result.elements[0 + 0 * 4] = scale.x;
		result.elements[1 + 1 * 4] = scale.y;
		result.elements[2 + 2 * 4] = scale.z;

		return result;
	}

}