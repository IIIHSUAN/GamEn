#include "GE_pch.h"
#include "Manager.h"

#include <GLFW/glfw3.h>
#include <Glad/glad.h>

namespace GamEn {

	Manager* Manager::_manager = nullptr;

	Manager::Manager()
	{
		if (_manager)
			CC_ERR("Manager may only be one");
		_manager = this;
		_window = std::unique_ptr<Window>(Window::create());
		_window->setEventCallback(BIND_FUNC(Manager::onEvent));  // bind callback func ptr from Window to Manager (where implement)
	}
	Manager::~Manager() {}

	void Manager::run()
	{
		while (_isRun)
		{
			glClearColor(0.02, 0.08, 0.13, 0.0);
			glClear(GL_COLOR_BUFFER_BIT);

			for (Layer* layer : _layerStack)
				layer->onUpdate();

			_window->onUpdate();
		}
	}
	void Manager::onEvent(Event& e)
	{
		EventHandler eHandler(e);
		eHandler.dispatch<WindowCloseEvent>(BIND_FUNC(Manager::onWindowClose));  // if on CloseEvent

		//CC_TRACE("{0}", e);

		for (auto it = _layerStack.end(); it != _layerStack.begin();)
		{
			(*--it)->onEvent(e);
			if (e.isHandled)
				break;
		}
	}

	void Manager::layer_push_front(Layer * layer)
	{
		_layerStack.push_front(layer);
		layer->onAttach();
	}
	void Manager::layer_push_back(Layer * layer)
	{
		_layerStack.push_back(layer);
		layer->onAttach();
	}

	bool Manager::onWindowClose(WindowCloseEvent & e)
	{
		_isRun = false;
		return true;
	}

}