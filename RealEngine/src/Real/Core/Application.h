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
	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			RE_CORE_ASSERT(index < Count);
			return Args[index];
		}
	};

	struct ApplicationSpecification
	{
		std::string Name = "Real Application";
		std::string WorkingDirectory;
		ApplicationCommandLineArgs CommandLineArgs;
	};

	class Application
	{
	public:
		Application(const ApplicationSpecification& specification);
		virtual ~Application();
		
		void OnEvent(Event& e);
		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		Window& GetWindow() { return *m_Window; }

		static Application& Get() { return *s_Instance; }
		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }
		const ApplicationSpecification& GetSpecification() const { return m_Specification; }
		void SubmitToMainThread(const std::function<void()>& function);
		void Close();
	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);
		void ExecuteMainThreadQueue();
	private:
		void Run();
		ApplicationSpecification m_Specification;
		Scope<Window> m_Window;
		ImGuiLayer* m_ImGuiLayer;
		bool m_Running = true;
		bool m_Minimized = false;
		LayerStack m_LayerStack;
		float m_LastFrameTime = 0.0f;
		std::vector<std::function<void()>> m_MainThreadQueue;
		std::mutex m_MainThreadQueueMutex;
	private:
		static Application* s_Instance;
		friend int ::main(int argc, char** argv);
	};

	//To be defined in client
	Application* CreateApplication(ApplicationCommandLineArgs args);


}