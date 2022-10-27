#pragma once

#include "RandomEngine/Maths/Maths.h"

namespace RandomEngine::Graphics {

	struct Transform {

			Maths::Vector3f Position;
			Maths::Vector3f Rotation;
			Maths::Vector3f Scale;

			Transform(
				Maths::Vector3f position = Maths::Vector3f(0.0f),
				Maths::Vector3f rotation = Maths::Vector3f(0.0f),
				Maths::Vector3f scale = Maths::Vector3f(1.0f)
			) : Position(position), Rotation(rotation), Scale(scale) { }

			operator Maths::Matrix4f() const {
				Maths::Matrix4f transform = Maths::Matrix4f::Translation(Position);
				transform = transform * Maths::Matrix4f::Rotation(Rotation.x, { 1, 0, 0 });
				transform = transform * Maths::Matrix4f::Rotation(Rotation.y, { 0, 1, 0 });
				transform = transform * Maths::Matrix4f::Rotation(Rotation.z, { 0, 0, 1 });
				transform = transform * Maths::Matrix4f::Scale(Scale);

				return transform;
			}
	};

}
