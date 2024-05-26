#include "repch.h"
#include "RenderCommand.h"

#include "Platform/OpenGL/OpenGLRendererAPI.h"

namespace Real {

	RendererAPI* RenderCommand::s_RendererAPI = new OpenGLRendererAPI;

}