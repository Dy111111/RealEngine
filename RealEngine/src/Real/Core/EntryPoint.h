#pragma once
#include"Real/Core/Base.h"
#ifdef RE_PLATFORM_WINDOWS

extern Real::Application* Real::CreateApplication();
int main(int argc,char** argv) {

	Real::Log::Init();
	RE_PROFILE_BEGIN_SESSION("Startup", "RealProfile-Startup.json");
	auto app = Real::CreateApplication();
	RE_PROFILE_END_SESSION();

	RE_PROFILE_BEGIN_SESSION("Runtime", "RealProfile-Runtime.json");
	app->Run();
	RE_PROFILE_END_SESSION();

	RE_PROFILE_BEGIN_SESSION("Shutdown", "RealProfile-Shutdown.json");
	delete app;
	RE_PROFILE_END_SESSION();
}
#endif