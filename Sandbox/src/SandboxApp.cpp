#include <Real.h>
#include <Real/Core/EntryPoint.h>
#include "Sandbox2D.h"
#include "ExampleLayer.h"
class Sandbox :public Real::Application {
public:
	Sandbox() {
		// PushLayer(new ExampleLayer());
		PushLayer(new Sandbox2D());
	};
	~Sandbox() {};
	
};

Real::Application* Real:: CreateApplication() {
	return new Sandbox();
}