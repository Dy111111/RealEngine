#pragma once
#ifdef RE_PLATFORM_WINDOWS
	#ifdef RE_BUILD_DLL
		#define REAL_API __declspec(dllexport)
	#else
		#define REAL_API __declspec(dllimport)
	#endif
#else
	#error Real only support windows!
#endif