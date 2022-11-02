#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Maths/Maths.h"

namespace RandomEngine {

	class Input {

		private:
			static Scope<Input> _instance;

		protected:
			Input() = default;

			virtual bool IsKeyPressedImpl(int keycode) = 0;
			virtual bool IsMouseButtonPressedImpl(int button) = 0;
			virtual Maths::Vector2f GetMousePositionImpl() = 0;

		public:
			Input(const Input&) = delete;
			Input& operator=(const Input&) = delete;

			static inline bool IsKeyPressed(int keycode) { return _instance->IsKeyPressedImpl(keycode); }
			static inline bool IsMouseButtonPressed(int button) { return _instance->IsMouseButtonPressedImpl(button); }
			static inline Maths::Vector2f GetMousePosition() { return _instance->GetMousePositionImpl(); }
	};

}
