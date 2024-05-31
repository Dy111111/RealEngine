#pragma once
#include"Real/Core/Core.h"
#ifdef RE_PLATFORM_WINDOWS

extern Real::Application* Real::CreateApplication();
int main(int argc,char** argv) {

	Real::Log::Init();
	RE_CORE_WARN("初始化日志Log!");
	
	int a = 5;
	RE_INFO("Hello! Var={0}", a);
	auto app = Real::CreateApplication();
	app->Run();
	delete app;
}
#endif