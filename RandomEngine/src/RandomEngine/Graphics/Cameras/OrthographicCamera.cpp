#include "REPCH.h"
#include "OrthographicCamera.h"

namespace RandomEngine::Graphics {

	OrthographicCamera::OrthographicCamera(float top, float right, float bottom, float left)
		: _projectionMatrix(Maths::Matrix4f::Orthographic(top, right, bottom, left, -1.0f, 1.0f)),
		  _viewMatrix(Maths::Matrix4f::Identity()) {
		_viewProjectionMatrix = _projectionMatrix * _viewMatrix;
	}

	void OrthographicCamera::SetProjection(float top, float right, float bottom, float left) {
		_projectionMatrix = Maths::Matrix4f::Orthographic(top, right, bottom, left, -1.0f, 1.0f);
		_viewProjectionMatrix = _projectionMatrix * _viewMatrix;
	}

	void OrthographicCamera::SetTransform(const Transform& transform) {
		_viewMatrix = Maths::Matrix4f::Inverse(transform);
		_viewProjectionMatrix = _projectionMatrix * _viewMatrix;
	}

}
