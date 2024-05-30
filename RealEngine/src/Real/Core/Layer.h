#pragma once

#include "Real/Core/Core.h"
#include "Real/Core/Events/Event.h"
#include "Real/Core/Timestep.h"
namespace Real {

	class REAL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer()=default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(TimeStep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}