#include <GamEn.h>

class myLayer : public GamEn::Layer
{
public:
	myLayer() :GamEn::Layer("Tester Layer") {}

	void onUpdate() override
	{
		LOG_INFO("testLayer update");
	}
	void onEvent(GamEn::Event& e) override
	{
		LOG_TRACE("{0}", e);
	}
};

class Tester : public GamEn::Manager
{
public:
	Tester()
	{
		layer_push_back(new myLayer());
	}
	~Tester() = default;
};


GamEn::Manager * GamEn::create()
{
	return new Tester();
}