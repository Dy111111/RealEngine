#pragma once
#include <memory>

namespace Real {

	void InitializeCore();
	void ShutdownCore();

}
#ifdef RE_PLATFORM_WINDOWS
#if RE_DYNAMIC_LINK
	#ifdef RE_BUILD_DLL
		#define REAL_API __declspec(dllexport)
	#else
		#define REAL_API __declspec(dllimport)
	#endif
#else
	#define REAL_API
#endif

#else
	#error Real only support windows!
#endif

#ifdef RE_DEBUG
	#define RE_ENABLE_ASSERTS
#endif
#ifdef RE_ENABLE_ASSERTS
#define RE_ASSERT(x, ...) { if(!(x)) { RE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#define RE_CORE_ASSERT(x, ...) { if(!(x)) { RE_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
#define RE_ASSERT(x, ...)
#define RE_CORE_ASSERT(x, ...)
#endif
#define BIT(x) (1 << x)