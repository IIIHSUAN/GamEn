#pragma once

#ifdef GE_PLATFORM_WIN

#ifdef GE_BUILD_DLL
#define GE_API __declspec(dllexport)
#else
#define GE_API __declspec(dllimport)
#endif

#else
#error ONLY RUNS ON WINDOWS ONLY

#endif

#define BIT(x) (1<<x)