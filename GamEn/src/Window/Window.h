#pragma once

// Window template for various platforms

#include "GE_pch.h"
#include "Core/Core.h"

#include "Core/Events/AppEvent.h"
#include "Core/Events/KeyEvent.h"
#include "Core/Events/MouseEvent.h"

namespace GamEn {

	struct WindowProperties
	{
		std::string title;
		unsigned int width;
		unsigned int height;

		WindowProperties(
			const std::string& _title = "GamEn's Window",
			unsigned int _width = 1280,
			unsigned int _height = 720
		) : title(_title), width(_width), height(_height) {}
	};

	class GE_API Window
	{
	public:
		virtual ~Window() = default;
		
		static Window* create(const WindowProperties& prop = WindowProperties());

		virtual void onUpdate() = 0;
		virtual unsigned int getWidth() const = 0;
		virtual unsigned int getHeight() const = 0;
		virtual void* getNativeWindow() const = 0;


		using EventCallback = std::function<void(Event&)>;  // func pointer

		virtual void setEventCallback(const EventCallback& callback) = 0;  // every eventcallback store in different struct
		virtual void setVSync(bool isEnable) = 0;
		virtual bool isVSync() const = 0;
	};

}