#include "GE_pch.h"
#include "IO.h"

#ifdef GE_PLATFORM_WIN
#include "Win_Input.h"
#elif GE_PLATFORM_LIN
#include "Lin_Input.h"
#else
#error PLATFORM NOT SUPPORTED
#endif

namespace GamEn
{
	
#ifdef GE_PLATFORM_WIN
	Input* Win_Input::_input = new Win_Input();
#elif GE_PLATFORM_LIN
	Input* Win_Input::_input = new Lin_Input();
#endif

}