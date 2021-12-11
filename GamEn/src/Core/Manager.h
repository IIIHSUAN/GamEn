#pragma once

#include "Core.h"
#include "Window/Window.h"
#include "Core/Events/Event.h"
#include "Core/Layers/LayerStack.h"

namespace GamEn {

	class GE_API Manager
	{
	public:
		Manager();
		virtual ~Manager();

		void run();
		void onEvent(Event& e);

		void layer_push_front(Layer* layer);
		void layer_push_back(Layer* layer);
	private:
		bool onWindowClose(WindowCloseEvent& e);
		bool onWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> _window;
		bool _isRun = true;
		LayerStack _layerStack;
	};

	Manager* create();  //define in application

}