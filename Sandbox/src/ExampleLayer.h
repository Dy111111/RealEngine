#pragma once

#include "Real.h"

class ExampleLayer : public Real::Layer
{
public:
	ExampleLayer();
	virtual ~ExampleLayer() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Real::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Real::Event& e) override;
private:
	Real::ShaderLibrary m_ShaderLibrary;
	Real::Ref<Real::Shader> m_Shader;
	Real::Ref<Real::VertexArray> m_VertexArray;

	Real::Ref<Real::Shader> m_FlatColorShader;
	Real::Ref<Real::VertexArray> m_SquareVA;

	Real::Ref<Real::Texture2D> m_Texture, m_ChernoLogoTexture;

	Real::OrthographicCameraController m_CameraController;
	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};