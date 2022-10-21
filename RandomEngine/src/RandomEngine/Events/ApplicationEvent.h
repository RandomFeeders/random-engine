#pragma once

#include "Event.h"

namespace RandomEngine {

	class WindowResizeEvent : public Event {

		protected:
			unsigned int _width, _height;

		public:
			WindowResizeEvent(unsigned int width, unsigned int height)
				: _width(width), _height(height) { }

			inline unsigned int GetWidth() const { return _width; }
			inline unsigned int GetHeight() const { return _height; }

			std::string ToString() const override {
				std::stringstream ss;
				ss << GetName() << ": " << _width << ", " << _height;
				return ss.str();
			}

			EVENT_CLASS_TYPE(WindowResize)
			EVENT_CLASS_CATEGORY(EC_Application)
	};

	class WindowCloseEvent : public Event {

		public:
			WindowCloseEvent() { }

			EVENT_CLASS_TYPE(WindowClose)
			EVENT_CLASS_CATEGORY(EC_Application)
	};

	class AppTickEvent : public Event {

		public:
			AppTickEvent() { }

			EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EC_Application)
	};

	class AppUpdateEvent : public Event {

		public:
			AppUpdateEvent() { }

			EVENT_CLASS_TYPE(AppUpdate)
			EVENT_CLASS_CATEGORY(EC_Application)
	};

	class AppRenderEvent : public Event {

		public:
			AppRenderEvent() { }

			EVENT_CLASS_TYPE(AppRender)
			EVENT_CLASS_CATEGORY(EC_Application)
	};

}