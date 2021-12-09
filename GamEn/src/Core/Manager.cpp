#include "GE_pch.h"
#include "Manager.h"

#include <GLFW/glfw3.h>

namespace GamEn {
	
#define BIND_FUNC(x) std::bind(&x, this, std::placeholders::_1)

	Manager::Manager()
	{
		_window = std::unique_ptr<Window>(Window::create());
		_window->setEventCallback(BIND_FUNC(Manager::onEvent));  //callback ptr
	}
	Manager::~Manager()
	{

	}

	void Manager::run()
	{
		while (_isRun)
		{
			glClearColor(0, 0.05, 0.1, 0.8);
			glClear(GL_COLOR_BUFFER_BIT);

			_window->onUpdate();
		}
	}
	void Manager::onEvent(Event& e)
	{
		EventHandler eHandler(e);
		eHandler.dispatch<WindowCloseEvent>(BIND_FUNC(Manager::onWindowClose));

		CC_TRACE("{0}", e);
	}
	bool Manager::onWindowClose(WindowCloseEvent & e)
	{
		_isRun = false;
		return true;
	}
}