#pragma once

#include "Real/Core.h"
#include "Real/Events/Event.h"
#include "Real/Core/Timestep.h"
namespace Real {

	class REAL_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer()=default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		inline const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}