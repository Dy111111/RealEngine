#include "repch.h"
#include "Real/Renderer/RenderCommand.h"

namespace Real {

	Scope<RendererAPI> RenderCommand::s_RendererAPI = RendererAPI::Create();

}