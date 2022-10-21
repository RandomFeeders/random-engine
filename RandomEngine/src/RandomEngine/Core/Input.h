#pragma once

#include "RandomEngine/Maths/Maths.h"

namespace RandomEngine {

	class Input {

		private:
			static Input* _instance;

		protected:
			virtual bool IsKeyPressedImpl(int keycode) = 0;
			virtual bool IsMouseButtonPressedImpl(int button) = 0;
			virtual Maths::Vector2f GetMousePositionImpl() = 0;

		public:
			static inline bool IsKeyPressed(int keycode) { return _instance->IsKeyPressedImpl(keycode); }
			static inline bool IsMouseButtonPressed(int button) { return _instance->IsMouseButtonPressedImpl(button); }
			static inline Maths::Vector2f GetMousePosition() { return _instance->GetMousePositionImpl(); }
	};

}