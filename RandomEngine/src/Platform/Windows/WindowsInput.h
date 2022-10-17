#pragma once

#include "REPCH.h"

#include <GLFW/glfw3.h>

#include "RandomEngine/Core.h"
#include "RandomEngine/Input.h"
#include "RandomEngine/Application.h"

namespace RandomEngine {

	class WindowsInput : public Input {

		protected:
			bool IsKeyPressedImpl(int keycode) override;
			bool IsMouseButtonPressedImpl(int button) override;
			Maths::Vector2f GetMousePositionImpl() override;
	};

}