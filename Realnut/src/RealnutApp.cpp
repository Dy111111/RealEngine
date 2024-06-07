#include <Real.h>
#include <Real/Core/EntryPoint.h>

#include "EditorLayer.h"

namespace Real {

	class Realnut : public Application
	{
	public:
		Realnut()
			: Application("Realnut")
		{
			PushLayer(new EditorLayer());
		}

		~Realnut()
		{
		}
	};

	Application* CreateApplication()
	{
		return new Realnut();
	}

}