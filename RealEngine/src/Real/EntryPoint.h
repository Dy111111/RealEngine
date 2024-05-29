#pragma once
#ifdef RE_PLATFORM_WINDOWS

extern Real::Application* Real::CreateApplication();
int main(int argc,char** argv) {

	Real::InitializeCore();
	Real::Application* app = Real::CreateApplication();
	RE_CORE_ASSERT(app, "Client Application is null!");
	app->Run();
	delete app;
	Real::ShutdownCore();
}
#endif