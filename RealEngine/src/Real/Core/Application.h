#pragma once
#include"Real/Core/Base.h"
#include"Real/Core/LayerStack.h"
#include"Real/Events/Event.h"
#include"Real/Events/ApplicationEvent.h"
#include"Real/ImGui/ImGuiLayer.h"
#include"Real/Core/Timestep.h"
#include"Real/Core/Window.h"

int main(int argc, char** argv);
namespace Real {
	class Application
	{
	public:
		Application(const std::string& name = "Real App");
		virtual ~Application();
		
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		static Application& Get() { return *s_Instance; }
		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		void Close();
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
	private:
		void Run();
		std::unique_ptr<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	//To be defined in client
	Application* CreateApplication();


}