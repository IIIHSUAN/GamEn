#pragma once

#include <GamEn.h>

#include "MyLayer.h"

class Tester : public GamEn::Manager
{
public:
	Tester()
	{
		layer_push_front(new MyLayer());
		layer_push_back(new GamEn::ImguiLayer());
	}
	~Tester() = default;
};