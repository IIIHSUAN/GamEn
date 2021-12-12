#pragma once

#include "Core/Manager.h"
#include "Core/Core.h"

namespace GamEn {

	class GE_API Input
	{
	public:
		static bool isPressKey(int key) { return _input->_isPressKey(key); }
		static bool isPressMouse(int botton) { return _input->_isPressMouse(botton); }

		static std::pair<float, float> pos() { return _input->_pos(); }
		static float posX() { return std::get<0>(_input->_pos()); }  // auto[x, y] = std::pair<float, float>(a, b); x = std::get<0>( std::pair<float, float>(a, b) );
		static float posY() { return std::get<1>(_input->_pos()); }
	protected:
		virtual bool _isPressKey(int key) = 0;
		virtual bool _isPressMouse(int botton) = 0;
		virtual std::pair<float, float> _pos() = 0;
	private:
		static Input* _input;
	};

}