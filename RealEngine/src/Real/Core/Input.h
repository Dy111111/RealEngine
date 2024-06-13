#pragma once
#include "Real/Core/KeyCodes.h"
#include "Real/Core/MouseCodes.h"
#include <glm/glm.hpp>
namespace Real {

	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key);

		static bool IsMouseButtonPressed(MouseCode button); 
		static glm::vec2 GetMousePosition(); 
		static float GetMouseX(); 
		static float GetMouseY(); 
	
	};

}