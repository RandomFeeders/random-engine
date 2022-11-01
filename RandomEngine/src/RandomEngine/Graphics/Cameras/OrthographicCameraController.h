#pragma once

#include "RandomEngine/Graphics/Cameras/OrthographicCamera.h"
#include "RandomEngine/Core/Timestep.h"
#include "RandomEngine/Events/ApplicationEvent.h"
#include "RandomEngine/Events/MouseEvent.h"
#include "RandomEngine/Maths/Maths.h"
#include "RandomEngine/Graphics/Objects/Transform.h"

namespace RandomEngine::Graphics {

	class OrthographicCameraController {

		private:
			bool _enableRotation;
			float _aspectRatio;
			float _zoomLevel;
			float _moveSpeed;
			float _rotationSpeed;

			Transform _transform;
			OrthographicCamera _camera;

			bool OnMouseScrolled(MouseScrolledEvent& e);
			bool OnWindowResized(WindowResizeEvent& e);

		public:
			OrthographicCameraController(float aspectRatio, bool enableRotation = false);

			void OnUpdate(Timestep ts);
			void OnEvent(Event& e);

			inline const OrthographicCamera& GetCamera() const { return _camera; }
	};

}
