#include "GE_pch.h"
#include "Manager.h"

#include <GLFW/glfw3.h>
#include <Glad/glad.h>

namespace GamEn {
	
#define BIND_FUNC(x) std::bind(&x, this, std::placeholders::_1)

	Manager::Manager()
	{
		_window = std::unique_ptr<Window>(Window::create());
		_window->setEventCallback(BIND_FUNC(Manager::onEvent));
	}
	Manager::~Manager() {}

	void Manager::run()
	{
		while (_isRun)
		{
			glClearColor(0, 0.05, 0.1, 0.0);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : _layerStack)
				layer->onUpdate();

			_window->onUpdate();
		}
	}
	void Manager::onEvent(Event& e)
	{
		EventHandler eHandler(e);
		eHandler.dispatch<WindowCloseEvent>(BIND_FUNC(Manager::onWindowClose));

		//CC_TRACE("{0}", e);

		for (auto it = _layerStack.end(); it != _layerStack.begin();)
		{
			(*--it)->onEvent(e);
			if (!e.isPropagation)
				break;
		}
	}

	void Manager::layer_push_front(Layer * layer)
	{
		_layerStack.push_front(layer);
	}
	void Manager::layer_push_back(Layer * layer)
	{
		_layerStack.push_back(layer);
	}

	bool Manager::onWindowClose(WindowCloseEvent & e)
	{
		_isRun = false;
		return true;
	}

}