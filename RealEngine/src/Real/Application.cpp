#include"repch.h"
#include "Application.h"
#include "Real/Events/ApplicationEvent.h"
#include "Real/Log.h"
#include<GLFW/glfw3.h>
namespace Real {
	Application::Application() {
		m_Window = std::unique_ptr<Window>(Window::Create());
	};
	Application::~Application() {};
	void Application::Run() {
		while(m_Running)
		{
			glClearColor(1, 1, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}
}