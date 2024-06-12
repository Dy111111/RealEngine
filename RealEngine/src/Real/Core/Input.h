#pragma once
#include <glm/glm.hpp>
#include "Real/Core/KeyCodes.h"
#include "Real/Core/MouseCodes.h"
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