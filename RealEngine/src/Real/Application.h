#pragma once
#include"Core.h"
namespace Real {
	class REAL_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};

	//To be defined in client
	Application* CreateApplication();

}