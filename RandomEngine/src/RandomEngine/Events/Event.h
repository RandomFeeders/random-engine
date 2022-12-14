#pragma once

#include "RandomEngine/Core/Base.h"
#include "RandomEngine/Core/Types.h"

namespace RandomEngine {

	enum class EventType {
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};

	enum EventCategory {
		None = 0,
		EC_Application	= BIT(0),
		EC_Input		= BIT(1),
		EC_Keyboard		= BIT(2),
		EC_Mouse		= BIT(3),
		EC_MouseButton	= BIT(4)
	};

	#define EVENT_CLASS_TYPE(type)	static EventType GetStaticType() { return EventType::type; }\
									virtual EventType GetEventType() const override { return GetStaticType(); }\
									virtual const char* GetName() const override { return #type; }

	#define EVENT_CLASS_CATEGORY(category) virtual int GetCategoryFlags() const override { return category; }


	class Event {
		friend class EventDispatcher;

		protected:
			bool _handled = false;

			virtual const char* GetName() const = 0;

		public:
			virtual EventType GetEventType() const = 0;			
			virtual int GetCategoryFlags() const = 0;
			virtual String ToString() const { return GetName(); }

			inline bool IsInCategory(EventCategory category) {
				return HAS_FLAG(GetCategoryFlags(), category);
			}

			inline bool IsHandled() const { return _handled; }
	};

	class EventDispatcher {

		private:
			Event& _event;

		public:
			EventDispatcher(Event& event)
				: _event(event) { }

			template<typename T, typename F>
			bool Dispatch(const F& func) {
				if (_event.GetEventType() == T::GetStaticType()) {
					_event._handled = func(static_cast<T&>(_event));
					return true;
				}
				return false;
			}
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e) {
		return os << e.ToString();
	}

	#define RE_BIND_EVENT_FN(func) std::bind(&func, this, std::placeholders::_1)

}
