#pragma once

#include "REPCH.h"

#include "RandomEngine/Maths/Maths.h"

namespace RandomEngine::Maths {

	struct Matrix4f {

		union {
			float elements[4 * 4];
			Vector4f columns[4];
		};

		Matrix4f();
		Matrix4f(float diagonal);

		Matrix4f& operator* (const Matrix4f& other);
		Matrix4f& operator*= (const Matrix4f& other);

		// Identity matrix
		static Matrix4f identity();

		// Projection matrices
		static Matrix4f orthographic(float top, float right, float bottom, float left, float near, float far);
		static Matrix4f perspective(float fov, float aspectRatio, float near, float far);

		// Translation matrices
		static Matrix4f translation(const Vector3f& translation);
		static Matrix4f rotation(float angle, const Vector3f& axis);
		static Matrix4f scale(const Vector3f& scale);
	};

}