#pragma once

#include "Core.h"
#include "Window/Window.h"


namespace GamEn {

	class GE_API Manager
	{
	public:
		Manager();
		virtual ~Manager();

		void run();
		void onEvent(Event& e);

	private:
		bool onWindowClose(WindowCloseEvent& e);
		bool onWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> _window;
		bool _isRun = true;
	};

	Manager* init();  //defined in application

}