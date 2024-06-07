#pragma once
#include"Real/Core/Base.h"
#include "Real/Core/KeyCodes.h"
#include "Real/Core/MouseCodes.h"
namespace Real {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button); 
		static std::pair<float, float> GetMousePosition(); 
		static float GetMouseX(); 
		static float GetMouseY(); 
	
	};

}