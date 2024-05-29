#pragma once
//为应用该引擎的程序准备的
#include"Real/Core/Application.h"
#include"Real/Core/Log.h"

#include "Real/Core/Events/Event.h"
#include "Real/Core/Events/ApplicationEvent.h"
#include "Real/Core/Events/KeyEvent.h"
#include "Real/Core/Events/MouseEvent.h"

#include "imgui/imgui.h"


// ---Renderer------------------------
#include "Real/Renderer/Renderer.h"
#include "Real/Renderer/Framebuffer.h"
#include "Real/Renderer/Buffer.h"
#include "Real/Renderer/Texture.h"
#include "Real/Renderer/Shader.h"
#include "Real/Renderer/Mesh.h"
#include "Real/Renderer/Camera.h"
// -----------------------------------
//-----Entry Point------
#include"Real/EntryPoint.h"