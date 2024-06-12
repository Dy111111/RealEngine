#pragma once

#include"Real/Core/Base.h"
// This ignores all warnings raised inside External headers
#pragma warning(push, 0)
#include<spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#pragma warning(pop)
namespace Real {
	class  Log
	{
	public:
		static void Init();

		static Ref<spdlog::logger>& GetCoreLogger() {
			return s_CoreLogger;
		}
		static Ref<spdlog::logger>& GetClientLogger() {
			return s_ClientLogger;
		}
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}
//Core log ºê
#define RE_CORE_TRACE(...)	::Real::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define RE_CORE_INFO(...)	::Real::Log::GetCoreLogger()->info(__VA_ARGS__)
#define RE_CORE_WARN(...)	::Real::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define RE_CORE_ERROR(...)	::Real::Log::GetCoreLogger()->error(__VA_ARGS__)
#define RE_CORE_CRITICAL(...)	::Real::Log::GetCoreLogger()->critical(__VA_ARGS__)

//Client log ºê
#define RE_TRACE(...)	::Real::Log::GetClientLogger()->trace(__VA_ARGS__)
#define RE_INFO(...)	::Real::Log::GetClientLogger()->info(__VA_ARGS__)
#define RE_WARN(...)	::Real::Log::GetClientLogger()->warn(__VA_ARGS__)
#define RE_ERROR(...)	::Real::Log::GetClientLogger()->error(__VA_ARGS__)
#define RE_CRITICAL(...)	::Real::Log::GetClientLogger()->critical(__VA_ARGS__)