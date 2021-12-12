#pragma once

#ifdef GE_PLATFORM_WIN

extern GamEn::Manager* GamEn::create();

int main(int argc, char** argv)
{
	GamEn::Log::init();
	CC_WARN("Entry point");

	auto app = GamEn::create();
	if (app)
	{
		app->run();
		delete app;
	}

	return 0;
}

#endif