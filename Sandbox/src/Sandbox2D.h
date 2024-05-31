#pragma once

#include "Real.h"

class Sandbox2D : public Real::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Real::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Real::Event& e) override;
private:
	Real::OrthographicCameraController m_CameraController;

	// Temp
	Real::Ref<Real::VertexArray> m_SquareVA;
	Real::Ref<Real::Shader> m_FlatColorShader;

	Real::Ref<Real::Texture2D> m_CheckerboardTexture;
	struct ProfileResult
	{
		const char* Name;
		float Time;
	};

	std::vector<ProfileResult> m_ProfileResults;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};