#include "REPCH.h"
#include "OrthographicCameraController.h"

#include "RandomEngine/Core/Input.h"
#include "RandomEngine/Core/KeyCodes.h"

namespace RandomEngine::Graphics {

	OrthographicCameraController::OrthographicCameraController(float aspectRatio, bool enableRotation)
		: _aspectRatio(aspectRatio), 
		_enableRotation(enableRotation), 
		_zoomLevel(1.0f), _moveSpeed(3.5f), _rotationSpeed(17.5f),
		_camera(_zoomLevel, _aspectRatio* _zoomLevel, -_zoomLevel, -_aspectRatio * _zoomLevel) { }

	void OrthographicCameraController::OnUpdate(Timestep ts) {
		using namespace Maths;

		if (Input::IsKeyPressed(RE_KEY_A))
			_transform.Position.x -= _moveSpeed * ts;

		if (Input::IsKeyPressed(RE_KEY_D))
			_transform.Position.x += _moveSpeed * ts;

		if (Input::IsKeyPressed(RE_KEY_S))
			_transform.Position.y -= _moveSpeed * ts;

		if (Input::IsKeyPressed(RE_KEY_W))
			_transform.Position.y += _moveSpeed * ts;

		if (_enableRotation) {
			if (RandomEngine::Input::IsKeyPressed(RE_KEY_Q))
				_transform.Rotation.z += _rotationSpeed * ts;

			if (RandomEngine::Input::IsKeyPressed(RE_KEY_E))
				_transform.Rotation.z -= _rotationSpeed * ts;
		}

		_camera.SetTransform(_transform);
	}

	void OrthographicCameraController::OnEvent(Event& e) {
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<MouseScrolledEvent>(
			RE_BIND_EVENT_FN(OrthographicCameraController::OnMouseScrolled)
		);
		dispatcher.Dispatch<WindowResizeEvent>(
			RE_BIND_EVENT_FN(OrthographicCameraController::OnWindowResized)
		);
	}

	bool OrthographicCameraController::OnMouseScrolled(MouseScrolledEvent& e) {
		_zoomLevel -= e.GetYOffset() * 0.25f;
		_zoomLevel = std::max(_zoomLevel, 0.25f);
		_zoomLevel = std::min(_zoomLevel, 10.0f);
		_moveSpeed = _zoomLevel * 3.5f;
		_camera.SetProjection(_zoomLevel, _aspectRatio * _zoomLevel, -_zoomLevel, -_aspectRatio * _zoomLevel);
		return false;
	}

	bool OrthographicCameraController::OnWindowResized(WindowResizeEvent& e) {
		_aspectRatio = (float)e.GetWidth() / (float)e.GetHeight();
		_camera.SetProjection(_zoomLevel, _aspectRatio * _zoomLevel, -_zoomLevel, -_aspectRatio * _zoomLevel);
		return false;
	}

}
