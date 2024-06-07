#pragma once

#include "Real/Core/Base.h"
#include "Real/Events/Event.h"
#include "Real/Core/Timestep.h"
namespace Real {

	class Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer()=default;

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnImGuiRender() {}
		virtual void OnEvent(Event& event) {}

		const std::string& GetName() const { return m_DebugName; }
	protected:
		std::string m_DebugName;
	};

}