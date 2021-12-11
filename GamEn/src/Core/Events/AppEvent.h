#pragma once

#include "Event.h"

namespace GamEn {

	class GE_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int height)
			: _width(width), _height(height) {}

		unsigned int GetWidth() const { return _width; }
		unsigned int GetHeight() const { return _height; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: (" << _width << ',' << _height << ')';
			return ss.str();
		}

		EVENT_TYPE_MACRO_FUNC(WindowResize)
		EVENT_CATEGORY_MACRO_FUNC(EventCategoryApplication)
	private:
		unsigned int _width, _height;
	};
	class GE_API WindowCloseEvent : public Event
	{
	public:
		WindowCloseEvent() = default;

		EVENT_TYPE_MACRO_FUNC(WindowClose)
		EVENT_CATEGORY_MACRO_FUNC(EventCategoryApplication)
	};

	class GE_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() = default;

		EVENT_TYPE_MACRO_FUNC(AppTick)
		EVENT_CATEGORY_MACRO_FUNC(EventCategoryApplication)
	};
	class GE_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() = default;

		EVENT_TYPE_MACRO_FUNC(AppUpdate)
		EVENT_CATEGORY_MACRO_FUNC(EventCategoryApplication)
	};
	class GE_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() = default;

		EVENT_TYPE_MACRO_FUNC(AppRender)
		EVENT_CATEGORY_MACRO_FUNC(EventCategoryApplication)
	};
}