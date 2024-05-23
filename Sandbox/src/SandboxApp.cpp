#include<Real.h>
#include"imgui/imgui.h"
class ExampleLayer : public Real::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		if (Real::Input::IsKeyPressed(RE_KEY_TAB))
			RE_TRACE("Tab key is pressed (poll)!");
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Test");
		ImGui::Text("Hello World");
		ImGui::End();
	}

	void OnEvent(Real::Event& event) override
	{
		if (event.GetEventType() == Real::EventType::KeyPressed)
		{
			Real::KeyPressedEvent& e = (Real::KeyPressedEvent&)event;
			if (e.GetKeyCode() == RE_KEY_TAB)
				RE_TRACE("Tab key is pressed (event)!");
			RE_TRACE("{0}", (char)e.GetKeyCode());
		}
	}

};
class Sandbox :public Real::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());

	};
	~Sandbox() {};
	
};

Real::Application* Real:: CreateApplication() {
	return new Sandbox();
}