#pragma once

#ifdef GE_PLATFORM_WIN

extern GamEn::Manager* GamEn::init();

int main(int argc, char** argv)
{
	GamEn::Log::init();
	CC_WARN("Entry point");

	auto app = GamEn::init();
	app->run();
	delete app;
	return 0;
}

#endif