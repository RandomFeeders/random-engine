#pragma once

#include "RandomEngine/Core/Input.h"

namespace RandomEngine {

	class WindowsInput : public Input {

		protected:
			bool IsKeyPressedImpl(KeyCode keycode) override;
			bool IsMouseButtonPressedImpl(MouseCode button) override;
			Maths::Vector2f GetMousePositionImpl() override;
	};

}
