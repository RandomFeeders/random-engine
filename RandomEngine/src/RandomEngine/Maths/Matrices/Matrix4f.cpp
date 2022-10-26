#include "REPCH.h"
#include "Matrix4f.h"

namespace RandomEngine::Maths {

	Matrix4f Matrix4f::Identity() {
		return Matrix4f(1.0f);
	}

	const float* Matrix4f::ToPointer() const {
		return glm::value_ptr(*((glm::mat4*)this));
	}

	Matrix4f Matrix4f::Orthographic(float top, float right, float bottom, float left, float near_, float far_) {

		// |  2 / (r - l)        0              0          -((r + l) / (r - l))  |
		// |      0          2 / (t - b)        0          -((t + b) / (t - b))  |
		// |      0              0         -2 / (f - n)    -((f + n) / (f - n))  |
		// |      0              0              0                    1           |

		Matrix4f result(1.0f);

		result[0][0] = 2.0f / (right - left);
		result[1][1] = 2.0f / (top - bottom);
		result[2][2] = -2.0f / (far_ - near_);

		result[3][0] = -((right + left) / (right - left));
		result[3][1] = -((top + bottom) / (top - bottom));
		result[3][2] = -((far_ + near_) / (far_ - near_));

		return result;
	}

	Matrix4f Matrix4f::Perspective(float fov, float aspectRatio, float near_, float far_) {

		// |  1 / (ar * tan(a / 2))          0                     0                         0             |
		// |           0               1 / tan(a / 2)              0                         0             |
		// |           0                     0           -((f + n) / (f - n))    -((2 * f * n) / (f - n))  |
		// |           0                     0                    -1                         0             |

		Matrix4f result(0.0f);

		
		float k = 1 / tan(glm::radians(fov / 2));
		float arm1 = 1.0f / aspectRatio;

		result[0][0] = k * arm1;
		result[1][1] = k;
		result[2][2] = -((far_ + near_) / (far_ - near_));
		result[2][3] = -1.0f;
		result[3][2] = -((2.0f * near_ * far_) / (far_ - near_));

		return result;
	}

	Matrix4f Matrix4f::Translation(const Vector3f& translation) {
		Matrix4f result(1.0f);

		result[3][0] = translation.x;
		result[3][1] = translation.y;
		result[3][2] = translation.z;

		return result;
	}

	Matrix4f Matrix4f::Rotation(float angle, const Vector3f& axis) {

		// |  (1 - c)xx + c    (1 - c)yx - sz   (1 - c)zx + sy   0  |
		// |  (1 - c)xy + sz   (1 - c)yy + c    (1 - c)zy - sx   0  |
		// |  (1 - c)xz - sy   (1 - c)yz + sx   (1 - c)zz + c    0  |
		// |        0                 0                0         1  |

		Matrix4f result(1.0f);

		float r = glm::radians(angle);
		float c = glm::cos(r);
		float s = glm::sin(r);
		float omc = 1 - c;

		result[0][0] = (axis.x * axis.x * omc) + (c);
		result[0][1] = (axis.x * axis.y * omc) + (s * axis.z);
		result[0][2] = (axis.x * axis.z * omc) - (s * axis.y);

		result[1][0] = (axis.y * axis.x * omc) - (s * axis.z);
		result[1][1] = (axis.y * axis.y * omc) + (c);
		result[1][2] = (axis.y * axis.z * omc) + (s * axis.x);

		result[2][0] = (axis.z * axis.x * omc) + (s * axis.y);
		result[2][1] = (axis.z * axis.y * omc) - (s * axis.x);
		result[2][2] = (axis.z * axis.z * omc) + (c);

		return result;
	}

	Matrix4f Matrix4f::Scale(const Vector3f& scale) {
		Matrix4f result(1.0f);

		result[0][0] = scale.x;
		result[1][1] = scale.y;
		result[2][2] = scale.z;

		return result;
	}

	const Matrix4f& Matrix4f::Inverse(const Matrix4f& matrix) {
		return glm::inverse(matrix);
	}

}
