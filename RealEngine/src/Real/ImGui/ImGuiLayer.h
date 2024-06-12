#pragma once

#include "Real/Core/Layer.h"
#include "Real/Events/ApplicationEvent.h"
#include "Real/Events/KeyEvent.h"
#include "Real/Events/MouseEvent.h"

namespace Real {

	class  ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer(); 
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnEvent(Event& e) override;
		
		void Begin();
		void End();
		void BlockEvents(bool block) { m_BlockEvents = block; }
		void SetDarkThemeColors();
	private:
		bool m_BlockEvents = true;
		float m_Time = 0.0f;
	};

}
