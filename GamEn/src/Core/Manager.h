#pragma once

#include "Core/Core.h"
#include "Window/Window.h"
#include "Core/IO/Input.h"
#include "Core/Events/Event.h"
#include "Core/Layers/LayerStack.h"

namespace GamEn {

	class GE_API Manager
	{
	public:
		Manager();
		virtual ~Manager();

		void run();
		void stop() { _isRun = false; }
		void onEvent(Event& e);  // call EventHandler & dipatch to Layers

		void layer_push_front(Layer* layer);
		void layer_push_back(Layer* layer);

		inline Window& getWindow() { return (Window&)*_window; }
		inline static Manager& get() { return *_manager; }
	private:
		static Manager* _manager;  // should implement one only

		bool onWindowClose(WindowCloseEvent& e);
		bool onWindowResize(WindowResizeEvent& e);

		std::unique_ptr<Window> _window;
		bool _isRun = true;
		LayerStack _layerStack;
	};

	Manager* create();  // implement on client

}