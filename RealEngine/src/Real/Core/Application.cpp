#include"repch.h"
#include "Real/Core/Application.h"
#include "Real/Core/Log.h"
#include "Real/Renderer/Renderer.h"
#include"Real/Core/Input.h"
#include"Real/Utils/PlatformUtils.h"

namespace Real {
	Application* Application::s_Instance = nullptr;

	
	Application::Application(const ApplicationSpecification& specification)
		: m_Specification(specification)
	{
		RE_PROFILE_FUNCTION();
		RE_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;
		// Set working directory here
		if (!m_Specification.WorkingDirectory.empty())
			std::filesystem::current_path(m_Specification.WorkingDirectory);

		m_Window = Window::Create(WindowProps(m_Specification.Name));
		m_Window->SetEventCallback([this](Event& event) {
			this->OnEvent(event);
			});
		Renderer::Init();
		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);

	};
	Application::~Application()
	{
		RE_PROFILE_FUNCTION();
		Renderer::Shutdown();
	}

	void Application::PushLayer(Layer* layer)
	{
		RE_PROFILE_FUNCTION();
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		RE_PROFILE_FUNCTION();
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}
	void Application::Close()
	{
		m_Running = false;
	}
	void Application::OnEvent(Event& e)
	{
		RE_PROFILE_FUNCTION();
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& event) {
			return this->OnWindowClose(event);
			});
		dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& event) {
			return this->OnWindowResize(event);
			});
		for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend();++it )
		{
			
			if (e.Handled)
				break;
			(*it)->OnEvent(e);
		}
	}
	void Application::Run() {
		RE_PROFILE_FUNCTION();
		while(m_Running)
		{
			RE_PROFILE_SCOPE("RunLoop");
			float time = Time::GetTime();
			Timestep timestep = time - m_LastFrameTime;
			m_LastFrameTime = time;

			if (!m_Minimized)
			{
				{
					RE_PROFILE_SCOPE("LayerStack OnUpdate");
					for (Layer* layer : m_LayerStack)
						layer->OnUpdate(timestep);
				}
				
			
				m_ImGuiLayer->Begin();
				{
					RE_PROFILE_SCOPE("LayerStack OnImGuiRender");
					for (Layer* layer : m_LayerStack)
						layer->OnImGuiRender();
				}
			
				m_ImGuiLayer->End();
			}

			m_Window->OnUpdate();
		}
	}
	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		RE_PROFILE_FUNCTION();
		if (e.GetWidth() == 0 || e.GetHeight() == 0)
		{
			m_Minimized = true;
			return false;
		}

		m_Minimized = false;
		Renderer::OnWindowResize(e.GetWidth(), e.GetHeight());

		return false;
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
}