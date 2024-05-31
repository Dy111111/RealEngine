#include "Sandbox2D.h"
#include "imgui/imgui.h"

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


Sandbox2D::Sandbox2D()
	: Layer("Sandbox2D"), m_CameraController(1280.0f / 720.0f)
{
}

void Sandbox2D::OnAttach()
{
	m_CheckerboardTexture = Real::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{
}

void Sandbox2D::OnUpdate(Real::Timestep ts)
{
	// Update
	m_CameraController.OnUpdate(ts);

	// Render
	Real::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
	Real::RenderCommand::Clear();

	Real::Renderer2D::BeginScene(m_CameraController.GetCamera());
	Real::Renderer2D::DrawQuad({ -1.0f, 0.0f }, { 0.8f, 0.8f }, { 0.8f, 0.2f, 0.3f, 1.0f });
	Real::Renderer2D::DrawQuad({ 0.5f, -0.5f }, { 0.5f, 0.75f }, { 0.2f, 0.3f, 0.8f, 1.0f });
	Real::Renderer2D::DrawQuad({ 0.0f, 0.0f, -0.1f }, { 10.0f, 10.0f }, m_CheckerboardTexture);
	Real::Renderer2D::EndScene();

	Real::Renderer::EndScene();
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Settings");
	ImGui::ColorEdit4("Square Color", glm::value_ptr(m_SquareColor));
	ImGui::End();
}

void Sandbox2D::OnEvent(Real::Event& e)
{
	m_CameraController.OnEvent(e);
}