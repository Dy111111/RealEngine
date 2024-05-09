workspace "RealEngine"
	architecture "x64"

	configurations{
		"Debug",
		"Release",
		"Dist"
	}
	startproject "Sandbox"
outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "RealEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "RealEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "RealEngine/vendor/imgui"

include "RealEngine/vendor/GLFW"
include "RealEngine/vendor/Glad"
include "RealEngine/vendor/imgui"



project "RealEngine"
	location "RealEngine"
	kind "SharedLib"
	language "c++"
	staticruntime "off"

	targetdir("bin/" ..outputdir.."/%{prj.name}")
	objdir("bin-int/" ..outputdir.."/%{prj.name}")

	pchheader "repch.h"
	pchsource "RealEngine/src/repch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}
	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"

		defines
		{
			"RE_PLATFORM_WINDOWS",
			"RE_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "RE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "RE_DIST"
		runtime "Release"
		optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "c++"
	staticruntime "off"

	targetdir("bin/" ..outputdir.."/%{prj.name}")
	objdir("bin-int/" ..outputdir.."/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
	}
	includedirs{
		"RealEngine/vendor/spdlog/include",
		"RealEngine/src"
	}
	links{
		"RealEngine"
	}
	filter "system:windows"
		cppdialect "c++17"
		systemversion "latest"

		defines
		{
			"RE_PLATFORM_WINDOWS"
		}

		 

	filter "configurations:Debug"
		defines "RE_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "RE_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "RE_DIST"
		runtime "Release"
		optimize "On"

	