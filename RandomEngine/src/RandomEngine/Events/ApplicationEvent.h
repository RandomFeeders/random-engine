#pragma once

#include "REPCH.h"

#include "Event.h"

namespace RandomEngine {

	class RANDOM_ENGINE_API WindowResizeEvent : public Event {

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

	class RANDOM_ENGINE_API WindowCloseEvent : public Event {

		public:
			WindowCloseEvent() { }

			EVENT_CLASS_TYPE(WindowClose)
			EVENT_CLASS_CATEGORY(EC_Application)
	};

	class RANDOM_ENGINE_API AppTickEvent : public Event {

		public:
			AppTickEvent() { }

			EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EC_Application)
	};

	class RANDOM_ENGINE_API AppUpdateEvent : public Event {

		public:
			AppUpdateEvent() { }

			EVENT_CLASS_TYPE(AppUpdate)
			EVENT_CLASS_CATEGORY(EC_Application)
	};

	class RANDOM_ENGINE_API AppRenderEvent : public Event {

		public:
			AppRenderEvent() { }

			EVENT_CLASS_TYPE(AppRender)
			EVENT_CLASS_CATEGORY(EC_Application)
	};

}