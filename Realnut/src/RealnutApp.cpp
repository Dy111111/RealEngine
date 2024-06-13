#include <Real.h>
#include <Real/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Real {

	class Realnut : public Application
	{
	public:
		Realnut(const ApplicationSpecification& spec)
			: Application(spec)
		{
			PushLayer(new EditorLayer());
		}

	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		ApplicationSpecification spec;
		spec.Name = "Realnut";
		spec.CommandLineArgs = args;

		return new Realnut(spec);
	}

}