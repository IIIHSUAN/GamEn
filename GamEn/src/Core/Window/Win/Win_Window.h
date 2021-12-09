#pragma once

#include "Core/Core.h"
#include <GLFW/glfw3.h>
#include "../Window.h"

namespace GamEn {

	class Win_Window : public Window
	{
	public:
		Win_Window(const WindowProperties& props);
		virtual ~Win_Window();

		void onUpdate() override;

		unsigned int getWidth() const override { return _winWindowData.width; }
		unsigned int getHeight() const override { return _winWindowData.height; }

		// Window attributes
		void setEventCallback(const EventCallback& callback) override { _winWindowData.eventCallback = callback; }
		void setVSync(bool isEnable) override;
		bool isVSync() const override;

		virtual void* GetNativeWindow() const { return _gLFWwindow; }
	private:
		virtual void init(const WindowProperties& props);
		virtual void shutdown();
	private:
		GLFWwindow* _gLFWwindow;

		struct WinWindowData
		{
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallback eventCallback;
		} _winWindowData;
	};

}