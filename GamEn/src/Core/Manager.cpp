#include "GE_pch.h"
#include "Manager.h"

#include <GLFW/glfw3.h>
#include <Glad/glad.h>

#include <glm/vec3.hpp> // glm::vec3
#include <glm/vec4.hpp> // glm::vec4
#include <glm/mat4x4.hpp> // glm::mat4
#include <glm/ext/matrix_transform.hpp> // glm::translate, glm::rotate, glm::scale
#include <glm/ext/matrix_clip_space.hpp> // glm::perspective
#include <glm/ext/scalar_constants.hpp> // glm::pi

namespace GamEn {

	Manager* Manager::_manager = nullptr;

	Manager::Manager()
	{
		if (_manager)
			CC_ERR("Manager may only be one");
		_manager = this;
		_window = std::unique_ptr<Window>(Window::create());
		_window->setEventCallback(BIND_FUNC(Manager::onEvent));  // bind callback func ptr from Window to Manager (where implement)
	
		_imguiLayer = new ImguiLayer();
		layer_push_back(_imguiLayer);
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

			_imguiLayer->begin();
			for(Layer* layer:_layerStack)
				layer->onImguiRender();
			_imguiLayer->end();

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