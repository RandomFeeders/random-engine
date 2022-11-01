#pragma once

#include "RandomEngine/Maths/Maths.h"
#include "RandomEngine/Graphics/Objects/Transform.h"

namespace RandomEngine::Graphics {

	class OrthographicCamera {

		private:
			Maths::Matrix4f _projectionMatrix;
			Maths::Matrix4f _viewMatrix;
			Maths::Matrix4f _viewProjectionMatrix;

		public:
			OrthographicCamera(float top, float right, float bottom, float left);

			void SetProjection(float top, float right, float bottom, float left);
			void SetTransform(const Transform& transform);

			inline const Maths::Matrix4f& GetProjectionMatrix() const { return _projectionMatrix; }
			inline const Maths::Matrix4f& GetViewMatrix() const { return _viewMatrix; }
			inline const Maths::Matrix4f& GetViewProjectionMatrix() const { return _viewProjectionMatrix; }
	};

}
