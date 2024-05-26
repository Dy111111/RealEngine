#pragma once
//为应用该引擎的程序准备的
#include"Real/Core/Application.h"
#include"Real/Core/Layer.h"
#include"Real/Core/Log.h"
#include "Real/Core/Timestep.h"
#include "Real/Core/Input.h"
#include "Real/Core/KeyCodes.h"
#include "Real/Core/MouseButtonCodes.h"

#include "Real/ImGui/ImGuiLayer.h"

// ---Renderer------------------------
#include "Real/Renderer/Renderer.h"
#include "Real/Renderer/RenderCommand.h"
		  
#include "Real/Renderer/Buffer.h"
#include "Real/Renderer/Shader.h"
#include "Real/Renderer/VertexArray.h"
		  
#include "Real/Renderer/OrthographicCamera.h"
// -----------------------------------
//-----Entry Point------
#include"Real/EntryPoint.h"