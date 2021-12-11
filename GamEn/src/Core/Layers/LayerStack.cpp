#include "GE_pch.h"
#include "LayerStack.h"

namespace GamEn {

	LayerStack::LayerStack()
	{
		_mid_ptr = _layers.begin();
	}
	LayerStack::~LayerStack()
	{
		// new outside
		for (Layer* layer : _layers)
			delete layer;
	}

	void GamEn::LayerStack::push_front(Layer * layer)
	{
		_mid_ptr = _layers.emplace(_mid_ptr, layer);
	}
	void GamEn::LayerStack::push_back(Layer * layer)
	{
		_layers.emplace_back(layer);
	}

	void GamEn::LayerStack::pop_front(Layer * layer)
	{
		auto it = std::find(_layers.begin(), _layers.end(), layer);

		if (it != _layers.end())
			_layers.erase(it), _mid_ptr--;
	}
	void GamEn::LayerStack::pop_back(Layer * layer)
	{
		auto it = std::find(_layers.begin(), _layers.end(), layer);

		if (it != _layers.end())
			_layers.erase(it);
	}

}