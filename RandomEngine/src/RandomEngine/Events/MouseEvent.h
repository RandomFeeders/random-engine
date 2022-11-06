#pragma once

#include "RandomEngine/Core/Types.h"
#include "RandomEngine/Core/KeyCodes.h"
#include "RandomEngine/Events/Event.h"

namespace RandomEngine {

	class MouseMovedEvent : public Event {
		
		protected:
			float _mouseX, _mouseY;

		public:
			MouseMovedEvent(float x, float y)
				: _mouseX(x), _mouseY(y) { }

			inline float GetX() const { return _mouseX; }
			inline float GetY() const { return _mouseY; }

			String ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _mouseX << ", " << _mouseY;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EC_Mouse | EC_Input)
	};

	class MouseScrolledEvent : public Event {

		protected:
			float _xOffset, _yOffset;

		public:
			MouseScrolledEvent(float xOffset, float yOffset)
				: _xOffset(xOffset), _yOffset(yOffset) { }

			inline float GetXOffset() const { return _xOffset; }
			inline float GetYOffset() const { return _yOffset; }

			String ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _xOffset << ", " << _yOffset;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EC_Mouse | EC_Input)
	};

	class MouseButtonEvent : public Event {

		protected:
			MouseCode _button;

			MouseButtonEvent(MouseCode button)
				: _button(button) { }

		public:
			inline MouseCode GetMouseButton() const { return _button; }

			EVENT_CLASS_CATEGORY(EC_Mouse | EC_Input)
	};


	class MouseButtonPressedEvent : public MouseButtonEvent {

		public:
			MouseButtonPressedEvent(MouseCode button)
				: MouseButtonEvent(button) { }

			String ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class MouseButtonReleasedEvent : public MouseButtonEvent {

		public:
			MouseButtonReleasedEvent(MouseCode button)
				: MouseButtonEvent(button) { }

			String ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _button;
				return ss.str();
			}

			EVENT_CLASS_TYPE(MouseButtonReleased)
	};
}
