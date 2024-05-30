#pragma once
#include <memory>

namespace Real {

	void InitializeCore();
	void ShutdownCore();

}
#ifdef RE_DEBUG
#define RE_ENABLE_ASSERTS
#endif
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

#ifdef RE_ENABLE_ASSERTS
#define RE_ASSERT_NO_MESSAGE(condition) { if(!(condition)) { RE_ERROR("Assertion Failed!"); __debugbreak(); } }
#define RE_ASSERT_MESSAGE(condition, ...) { if(!(condition)) { RE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }

#define RE_ASSERT_RESOLVE(arg1, arg2, macro, ...) macro

#define RE_ASSERT(...) RE_ASSERT_RESOLVE(__VA_ARGS__, RE_ASSERT_MESSAGE, RE_ASSERT_NO_MESSAGE)(__VA_ARGS__)
#define RE_CORE_ASSERT(...) RE_ASSERT_RESOLVE(__VA_ARGS__, RE_ASSERT_MESSAGE, RE_ASSERT_NO_MESSAGE)(__VA_ARGS__)
#else
#define RE_ASSERT(...)
#define RE_CORE_ASSERT(...)
#endif
#define BIT(x) (1 << x)

// Pointer wrappers
namespace Real {

	template<typename T>
	using Scope = std::unique_ptr<T>;

	template<typename T>
	using Ref = std::shared_ptr<T>;

	using byte = unsigned char;

}