#pragma once

#include "Core/Core.h"
#include "Layer.h"

namespace GamEn {

	class GE_API LayerStack
	{
	public:
		LayerStack();
		~LayerStack();

		void push_front(Layer* layer);
		void push_back(Layer* layer);

		void pop_front(Layer* layer);
		void pop_back(Layer* layer);

		std::vector<Layer*>::iterator begin() { return _layers.begin(); }
		std::vector<Layer*>::iterator end() { return _layers.end(); }
	private:
		std::vector<Layer*>_layers;
		unsigned int _mid_layer_ind = 0;
	};

}