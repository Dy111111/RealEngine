#pragma once
#include"Real/Core/Core.h"
#include"Real/Core/Window.h"
#include"Real/Core/LayerStack.h"
#include"Real/Core/Events/Event.h"
#include"Real/Core/Events/ApplicationEvent.h"
#include"Real/ImGui/ImGuiLayer.h"
//#include "Real/Core/Timestep.h"

namespace Real {
	class Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();

		virtual void OnInit() {}
		virtual void OnShutdown() {}
		virtual void OnUpdate() {}

		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);
		void RenderImGui();

		std::string OpenFile(const std::string& filter) const;

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	private:
		bool OnWindowResize(WindowResizeEvent& e);
		bool OnWindowClose(WindowCloseEvent& e);
	private:
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		LayerStack m_LayerStack;
	private:
		static Application* s_Instance;
	};

	//To be defined in client
	Application* CreateApplication();


}