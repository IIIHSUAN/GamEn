#pragma once

#include "Event.h"

namespace GamEn {

	class GE_API KeyEvent : public Event
	{
	public:
		KeyCode getKeyCode() const { return _keyCode; }
		EVENT_CATEGORY_MACRO_FUNC(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(const KeyCode keycode)
			: _keyCode(keycode) {}

		KeyCode _keyCode;
	};

	class GE_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(const KeyCode keyCode, const uint16_t repeatCount)
			: KeyEvent(keyCode), _repeatCount(repeatCount) {}

		uint16_t getRepeatCount() const { return _repeatCount; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << _keyCode << " (" << _repeatCount << " repeats)";
			return ss.str();
		}

		EVENT_TYPE_MACRO_FUNC(KeyPressed)
	private:
		uint16_t _repeatCount;
	};
	class GE_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_TYPE_MACRO_FUNC(KeyReleased)
	};
	class GE_API KeyTypedEvent : public KeyEvent
	{
	public:
		KeyTypedEvent(const KeyCode keycode)
			: KeyEvent(keycode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyTypedEvent: " << _keyCode;
			return ss.str();
		}

		EVENT_TYPE_MACRO_FUNC(KeyTyped)
	};
}