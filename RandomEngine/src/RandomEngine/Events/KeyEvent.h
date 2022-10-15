#pragma once

#include "REPCH.h"

#include "Event.h"

namespace RandomEngine {

	class KeyEvent : public Event {

		protected:
			int _keyCode;

			KeyEvent(int keyCode)
				: _keyCode(keyCode) { }

		public:
			inline int GetKeyCode() const { return _keyCode; }

			EVENT_CLASS_CATEGORY(EC_Keyboard | EC_Input)
	};

	class KeyPressedEvent : public KeyEvent {
		
		protected:
			int _repeatCount;

		public:
			KeyPressedEvent(int keyCode, int repeatCount)
				: KeyEvent(keyCode), _repeatCount(repeatCount) { }

			inline int GetRepeatCount() const { return _repeatCount; }

			std::string ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _keyCode << " (" << _repeatCount << " repeats)";
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyPressed)
	};

	class KeyReleasedEvent : public KeyEvent {

		public:
			KeyReleasedEvent(int keyCode)
				: KeyEvent(keyCode) { }

			std::string ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _keyCode;
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyReleased)
	};

	class KeyTypedEvent : public KeyEvent {

		public:
			KeyTypedEvent(int keyCode)
				: KeyEvent(keyCode) { }

			std::string ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _keyCode;
				return ss.str();
			}

			EVENT_CLASS_TYPE(KeyTyped)
	};

}