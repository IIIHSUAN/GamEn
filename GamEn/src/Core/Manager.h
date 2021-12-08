#pragma once

#include "Core.h"

namespace GamEn {

	class GE_API Manager
	{
	public:
		Manager();
		virtual ~Manager();

		void run();
	};

	Manager* init();  //defined in application
}