#include<GamEn.h>

class Tester : public GamEn::Manager
{
public:
	Tester()
	{

	}
};


GamEn::Manager * GamEn::init()
{
	return new GamEn::Manager();
}