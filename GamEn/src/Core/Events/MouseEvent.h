#pragma once

#include "Event.h"

namespace GamEn {

	class GE_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(const float mouseX, const float mouseY)
			: _mouseX(mouseX), _mouseY(mouseY) {}

		float getX() const { return _mouseX; }
		float getY() const { return _mouseY; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseMovedEvent: (" << _mouseX << ',' << _mouseY << ')';
			return ss.str();
		}

		EVENT_TYPE_MACRO_FUNC(MouseMoved)
		EVENT_CATEGORY_MACRO_FUNC(EventCategoryMouse | EventCategoryInput)
	private:
		float _mouseX, _mouseY;
	};

	class GE_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(const float offsetX, const float offsetY)
			: _offsetX(offsetX), _offsetY(offsetY) {}

		float getOffsetX() const { return _offsetX; }
		float getOffsetY() const { return _offsetY; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseScrolledEvent: (" << getOffsetX() << ',' << getOffsetY() << ')';
			return ss.str();
		}

		EVENT_TYPE_MACRO_FUNC(MouseScrolled)
		EVENT_CATEGORY_MACRO_FUNC(EventCategoryMouse | EventCategoryInput)
	private:
		float _offsetX, _offsetY;
	};

	class GE_API MouseButtonEvent : public Event
	{
	public:
		MouseCode getMouseButton() const { return _mouseBotton; }

		EVENT_CATEGORY_MACRO_FUNC(EventCategoryMouse | EventCategoryInput | EventCategoryMouseButton)
	protected:
		MouseButtonEvent(const MouseCode button)
			: _mouseBotton(button) {}

		MouseCode _mouseBotton;
	};

	class GE_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(const MouseCode button)
			: MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << _mouseBotton;
			return ss.str();
		}

		EVENT_TYPE_MACRO_FUNC(MouseButtonPressed)
	};

	class GE_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(const MouseCode button)
			: MouseButtonEvent(button) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << _mouseBotton;
			return ss.str();
		}

		EVENT_TYPE_MACRO_FUNC(MouseButtonReleased)
	};

}
