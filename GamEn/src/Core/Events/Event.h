#pragma once

#include "Core/Core.h"

namespace GamEn {

	// current event method: blocking-event  // todo: nonblocking, queue events

	// generate code
#define EVENT_CLASS_TYPE(type) \
	static EventType getPrototype() { return EventType::type; }\
	virtual EventType getType() const override { return getPrototype(); }\
	virtual const char* getName() const override { return #type; }

#define EVENT_CLASS_CATEGORY(category) virtual int getCategoryFlags() const override { return category; }


	enum class EventType
	{
		None = 0,
		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,
		AppTick, AppUpdate, AppRender,
		KeyPressed, KeyReleased, KeyTyped,
		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled
	};
	enum EventCategory
	{
		None = 0,
		EventCategoryApplication = BIT(0),
		EventCategoryInput = BIT(1),
		EventCategoryKeyboard = BIT(2),
		EventCategoryMouse = BIT(3),
		EventCategoryMouseButton = BIT(4)
	};

	class GE_API Event
	{
	public:
		virtual ~Event() = default;

		bool isHandle = false;

		// override
		virtual EventType getType() const = 0;
		virtual const char* getName() const = 0;
		virtual int getCategoryFlags() const = 0;
		virtual std::string toString() const { return getName(); }

		inline bool isCategory(EventCategory category)
		{
			return getCategoryFlags() & category;
		}
	};

	class GE_API EventHandler
	{
	public:
		EventHandler(Event& event)
			: _event(event)
		{
		}

		// Func will be deduced by the compiler
		template<typename T, typename Func>
		bool dispatch(const Func& func)
		{
			if (_event.getType() == T::getPrototype())
			{
				_event.isHandle |= func(static_cast<T&>(_event));
				return true;
			}
			return false;
		}
	private:
		Event& _event;
	};

	inline std::ostream& operator<<(std::ostream& os, const Event& e)
	{
		return os << e.toString();
	}

}

