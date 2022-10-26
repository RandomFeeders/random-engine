#include "REPCH.h"
#include "OrthographicCamera.h"

namespace RandomEngine::Graphics {

	OrthographicCamera::OrthographicCamera(float top, float right, float bottom, float left)
		: _projectionMatrix(Maths::Matrix4f::Orthographic(top, right, bottom, left, -1.0f, 1.0f)),
		  _viewMatrix(Maths::Matrix4f::Identity()),
		  _position({ 0.0f, 0.0f, 0.0f }), _rotation({ 0.0f, 0.0f, 0.0f }) {
		_viewProjectionMatrix = _projectionMatrix * _viewMatrix;
	}

	void OrthographicCamera::RecalculateViewMatrix() {
		Maths::Matrix4f transform = Maths::Matrix4f::Translation(_position);
		transform = transform * Maths::Matrix4f::Rotation(_rotation.x, { 1, 0, 0 });
		transform = transform * Maths::Matrix4f::Rotation(_rotation.y, { 0, 1, 0 });
		transform = transform * Maths::Matrix4f::Rotation(_rotation.z, { 0, 0, 1 });

		_viewMatrix = Maths::Matrix4f::Inverse(transform);
		_viewProjectionMatrix = _projectionMatrix * _viewMatrix;
	}

}
