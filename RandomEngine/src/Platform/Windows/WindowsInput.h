#pragma once

#include "RandomEngine/Core/Input.h"

namespace RandomEngine {

	class WindowsInput : public Input {

		protected:
			bool IsKeyPressedImpl(int keycode) override;
			bool IsMouseButtonPressedImpl(int button) override;
			Maths::Vector2f GetMousePositionImpl() override;
	};

}