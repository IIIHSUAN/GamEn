#pragma once

#ifdef GE_PLATFORM_WIN

#ifdef GE_BUILD_DLL
#define GE_API __declspec(dllexport)
#else
#define GE_API __declspec(dllimport)
#endif

#else
#error WINDOWS ONLY
#endif