#pragma once
//为应用该引擎的程序准备的
#include"Real/Application.h"
#include"Real/Layer.h"
#include"Real/Log.h"
#include "Real/Core/Timestep.h"
#include "Real/Input.h"
#include "Real/KeyCodes.h"
#include "Real/MouseButtonCodes.h"
#include "Real/OrthographicCameraController.h"

#include "Real/ImGui/ImGuiLayer.h"

// ---Renderer------------------------
#include "Real/Renderer/Renderer.h"
#include "Real/Renderer/RenderCommand.h"
		  
#include "Real/Renderer/Buffer.h"
#include "Real/Renderer/Shader.h"
#include"Real/Renderer/Texture.h"
#include "Real/Renderer/VertexArray.h"
		  
#include "Real/Renderer/OrthographicCamera.h"
// -----------------------------------
//-----Entry Point------
#include"Real/EntryPoint.h"