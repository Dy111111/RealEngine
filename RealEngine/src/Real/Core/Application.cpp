#include"repch.h"
#include "Application.h"

#include "Real/Renderer/Renderer.h"
#include "Real/Renderer/Framebuffer.h"
#include <glfw/glfw3.h>
#include <imgui/imgui.h>

#define GLFW_EXPOSE_NATIVE_WIN32//?
#include <GLFW/glfw3native.h>
#include <Windows.h>
namespace Real {
	Application* Application::s_Instance = nullptr;

	
	Application::Application()
	{
		s_Instance = this;
		m_Window = std::unique_ptr<Window>(Window::Create());
		m_Window->SetEventCallback([this](Event& event) {
			this->OnEvent(event);
			});
		m_Window->SetVSync(false);
		m_ImGuiLayer = new ImGuiLayer("ImGui");
		PushOverlay(m_ImGuiLayer);
		Renderer::Init();
	};
	Application::~Application() {};
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();
	}

	void Application::PushOverlay(Layer* layer)
	{
		m_LayerStack.PushOverlay(layer);
		layer->OnAttach();
	}

	void Application::RenderImGui()
	{
		m_ImGuiLayer->Begin();

		ImGui::Begin("Renderer");
		auto& caps = RendererAPI::GetCapabilities();
		ImGui::Text("Vendor: %s", caps.Vendor.c_str());
		ImGui::Text("Renderer: %s", caps.Renderer.c_str());
		ImGui::Text("Version: %s", caps.Version.c_str());
		ImGui::Text("Frame Time: %.2fms\n", m_TimeStep.GetMilliseconds());
		ImGui::End();

		for (Layer* layer : m_LayerStack)
			layer->OnImGuiRender();

		m_ImGuiLayer->End();
	}


	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>([this](WindowCloseEvent& event) {
			return this->OnWindowClose(event);
			});
		dispatcher.Dispatch<WindowResizeEvent>([this](WindowResizeEvent& event) {
			return this->OnWindowResize(event);
			});
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin(); )
		{
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}
	void Application::Run() {
		OnInit();
		while (m_Running)
		{
			if (!m_Minimized)
			{
				for (Layer* layer : m_LayerStack)
					layer->OnUpdate(m_TimeStep);

				// Render ImGui on render thread
				Application* app = this;
				RE_RENDER_1(app, { app->RenderImGui(); });

				Renderer::Get().WaitAndRender();
			}

			m_Window->OnUpdate();
			float time = GetTime();
			m_TimeStep = time - m_LastFrameTime;
			m_LastFrameTime = time;
		}
		OnShutdown();
	}
	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}
	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		int width = e.GetWidth(), height = e.GetHeight();
		if(width == 0 || height == 0)
		{
			m_Minimized = true;
			return false;
		}
		m_Minimized = false;
		RE_RENDER_2(width, height, { glViewport(0, 0, width, height); });
		auto& fbs = FramebufferPool::GetGlobal()->GetAll();
		for (auto& fb : fbs)
			fb->Resize(width, height);
		return false;
	}
	std::string Application::OpenFile(const std::string& filter) const
	{
		OPENFILENAMEA ofn;       // common dialog box structure
		CHAR szFile[260] = { 0 };       // if using TCHAR macros

		// Initialize OPENFILENAME
		ZeroMemory(&ofn, sizeof(OPENFILENAME));
		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.hwndOwner = glfwGetWin32Window((GLFWwindow*)m_Window->GetNativeWindow());
		ofn.lpstrFile = szFile;
		ofn.nMaxFile = sizeof(szFile);
		ofn.lpstrFilter = "All\0*.*\0";
		ofn.nFilterIndex = 1;
		ofn.lpstrFileTitle = NULL;
		ofn.nMaxFileTitle = 0;
		ofn.lpstrInitialDir = NULL;
		ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

		if (GetOpenFileNameA(&ofn) == TRUE)
		{
			return ofn.lpstrFile;
		}
		return std::string();
	}

	float Application::GetTime() const
	{
		return (float)glfwGetTime();
	}
}