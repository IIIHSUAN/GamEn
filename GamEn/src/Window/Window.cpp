#include "GE_pch.h"
#include "Window.h"

#ifdef GE_PLATFORM_WIN
#include "Win/Win_Window.h"  // include glfw, glad
#elif GE_PLATFORM_LIN
#include "Lin/Lin_Window.h"
#else
#error PLATFORM NOT SUPPORTED
#endif

namespace GamEn
{

	Window* Window::create(const WindowProperties& props)
	{
#ifdef GE_PLATFORM_WIN
		return new Win_Window(props);  //as unique_ptr
#elif GE_PLATFORM_LIN
		return new Lin_Window(props);  //as unique_ptr
#endif
	}

}