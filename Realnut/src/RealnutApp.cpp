#include <Real.h>
#include <Real/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Real {

	class Realnut : public Application
	{
	public:
		Realnut(ApplicationCommandLineArgs args)
			: Application("Real", args)
		{
			PushLayer(new EditorLayer());
		}

		~Realnut()
		{
		}
	};

	Application* CreateApplication(ApplicationCommandLineArgs args)
	{
		return new Realnut(args);
	}

}