#pragma once

#include "RandomEngine/Maths/Maths.h"

namespace RandomEngine::Graphics {

	class OrthographicCamera {

		private:
			Maths::Matrix4f _projectionMatrix;
			Maths::Matrix4f _viewMatrix;
			Maths::Matrix4f _viewProjectionMatrix;

			Maths::Vector3f _position;
			Maths::Vector3f _rotation;

			void RecalculateViewMatrix();

		public:
			OrthographicCamera(float top, float right, float bottom, float left);

			inline const Maths::Vector3f& GetPosition() const { return _position; }
			inline void SetPosition(const Maths::Vector3f& position) { 
				_position = position; 
				RecalculateViewMatrix();
			}

			inline const Maths::Vector3f& GetRotation() const { return _rotation; }
			inline void SetRotation(const Maths::Vector3f& rotation) {
				_rotation = rotation; 
				RecalculateViewMatrix();
			}

			inline const Maths::Matrix4f& GetProjectionMatrix() const { return _projectionMatrix; }
			inline const Maths::Matrix4f& GetViewMatrix() const { return _viewMatrix; }
			inline const Maths::Matrix4f& GetViewProjectionMatrix() const { return _viewProjectionMatrix; }
	};

}
