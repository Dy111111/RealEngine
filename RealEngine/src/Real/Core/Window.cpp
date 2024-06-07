#include "repch.h"
#include "Real/Core/Window.h"

#ifdef RE_PLATFORM_WINDOWS
#include "Platform/Windows/WindowsWindow.h"
#endif

namespace Real
{
	Scope<Window> Window::Create(const WindowProps& props)
	{
#ifdef RE_PLATFORM_WINDOWS
		return CreateScope<WindowsWindow>(props);
#else
		RE_CORE_ASSERT(false, "Unknown platform!");
		return nullptr;
#endif
	}

}