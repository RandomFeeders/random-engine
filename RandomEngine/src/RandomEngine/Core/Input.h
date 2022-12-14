#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Maths/Maths.h"
#include "RandomEngine/Core/KeyCodes.h"

namespace RandomEngine {

	class Input {

		private:
			static Scope<Input> _instance;

			static Scope<Input> Create();

		protected:
			Input() = default;

			virtual bool IsKeyPressedImpl(KeyCode keycode) = 0;
			virtual bool IsMouseButtonPressedImpl(MouseCode button) = 0;
			virtual Maths::Vector2f GetMousePositionImpl() = 0;

		public:
			Input(const Input&) = delete;
			Input& operator=(const Input&) = delete;

			static inline bool IsKeyPressed(KeyCode keycode) { return _instance->IsKeyPressedImpl(keycode); }
			static inline bool IsMouseButtonPressed(MouseCode button) { return _instance->IsMouseButtonPressedImpl(button); }
			static inline Maths::Vector2f GetMousePosition() { return _instance->GetMousePositionImpl(); }
	};

}
