#pragma once
//为应用该引擎的程序准备的
#include"Real/Core/Base.h"
#include"Real/Core/Application.h"
#include"Real/Core/Layer.h"
#include"Real/Core/Log.h"
#include"Real/Core/Assert.h"
#include"Real/Core/Timestep.h"
#include"Real/Core/Input.h"
#include"Real/Core/KeyCodes.h"
#include"Real/Core/MouseCodes.h"
#include"Real/Renderer/OrthographicCameraController.h"

#include"Real/ImGui/ImGuiLayer.h"

#include "Real/Scene/Scene.h"
#include "Real/Scene/Components.h"
#include "Real/Scene/Entity.h"
#include "Real/Scene/ScriptableEntity.h"

// ---Renderer------------------------
#include"Real/Renderer/Renderer.h"
#include"Real/Renderer/Renderer2D.h"
#include"Real/Renderer/RenderCommand.h"
		  
#include"Real/Renderer/Buffer.h"
#include"Real/Renderer/Shader.h"
#include"Real/Renderer/Texture.h"
#include "Real/Renderer/Framebuffer.h"
#include"Real/Renderer/VertexArray.h"
		  
#include "Real/Renderer/OrthographicCamera.h"