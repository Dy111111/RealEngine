#include "repch.h"
#include "Core.h"

#include "Log.h"

#define REAL_BUILD_ID "v0.1a"

namespace Real {

	void InitializeCore()
	{
		Real::Log::Init();

		RE_CORE_TRACE("Real Engine {}", REAL_BUILD_ID);
		RE_CORE_TRACE("Initializing...");
	}

	void ShutdownCore()
	{
		RE_CORE_TRACE("Shutting down...");
	}

}