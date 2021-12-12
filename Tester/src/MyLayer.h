#pragma once

#include <GamEn.h>

#include "Tester.h"

class MyLayer : public GamEn::Layer
{
public:
	MyLayer() :GamEn::Layer("Tester Layer") {}

	void onUpdate() override
	{
		//LOG_INFO("testLayer update");


	}
	void onEvent(GamEn::Event& e) override
	{
		LOG_TRACE("{0}", e);
		if (GamEn::Input::isPressKey(GamEn::Key::Escape))
			GamEn::Manager::get().stop();
	}
};
