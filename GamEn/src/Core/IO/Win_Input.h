#pragma once

#include "Input.h"

namespace GamEn {

	class GE_API Win_Input: public Input
	{
	protected:
		virtual bool _isPressKey(int key) override;
		virtual bool _isPressMouse(int botton) override;
		virtual std::pair<float, float> _pos() override;
	};

}