#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Core/KeyCodes.h"
#include "RandomEngine/Events/Event.h"

namespace RandomEngine {

	class KeyEvent : public Event {

		protected:
			KeyCode _keyCode;

			KeyEvent(KeyCode keyCode)
				: _keyCode(keyCode) { }

		public:
			inline KeyCode GetKeyCode() const { return _keyCode; }

			EVENT_CLASS_CATEGORY(EC_Keyboard | EC_Input)
	};

	class KeyPressedEvent : public KeyEvent {
		
		protected:
			int _repeatCount;

		public:
			KeyPressedEvent(KeyCode keyCode, int repeatCount)
				: KeyEvent(keyCode), _repeatCount(repeatCount) { }

			inline int GetRepeatCount() const { return _repeatCount; }

			String ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _keyCode << " (" << _repeatCount << " repeats)";
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyPressed)
	};

	class KeyReleasedEvent : public KeyEvent {

		public:
			KeyReleasedEvent(KeyCode keyCode)
				: KeyEvent(keyCode) { }

			String ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _keyCode;
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent {

		public:
			KeyTypedEvent(KeyCode keyCode)
				: KeyEvent(keyCode) { }

			String ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _keyCode;
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyTyped)
	};

}
