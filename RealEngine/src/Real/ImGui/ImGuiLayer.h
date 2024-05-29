#pragma once
#include"repch.h"
#include "Real/Core/Layer.h"


namespace Real {

	class REAL_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer(const std::string& name);
		~ImGuiLayer();

		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		
		void Begin();
		void End();
	private:
		float m_Time = 0.0f;
	};

}
