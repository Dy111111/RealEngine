workspace "RealEngine"
	architecture "x64"
	startproject "Sandbox"
	configurations{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"] = "RealEngine/vendor/GLFW/include"
IncludeDir["Glad"] = "RealEngine/vendor/Glad/include"
IncludeDir["ImGui"] = "RealEngine/vendor/imgui"
IncludeDir["glm"] = "RealEngine/vendor/glm"

include "RealEngine/vendor/GLFW"
include "RealEngine/vendor/Glad"
include "RealEngine/vendor/imgui"


project "RealEngine"
	location "RealEngine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" ..outputdir.."/%{prj.name}")
	objdir("bin-int/" ..outputdir.."/%{prj.name}")

	pchheader "repch.h"
	pchsource "RealEngine/src/repch.cpp"

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/src/**.hpp",
	}
	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
		"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
	}
	includedirs{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/vendor",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{prj.name}/vendor/assimp/include",
        "%{prj.name}/vendor/stb/include"
	}
	links{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"RE_PLATFORM_WINDOWS",
			"RE_BUILD_DLL",
		}


	filter "configurations:Debug"
		defines "RE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RE_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "RE_DIST"
		runtime "Release"
		optimize "on"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir("bin/" ..outputdir.."/%{prj.name}")
	objdir("bin-int/" ..outputdir.."/%{prj.name}")

	files{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.c",
		"%{prj.name}/src/**.hpp",
		"%{prj.name}/src/**.cpp",
	}
	includedirs{
		"%{prj.name}/src",
		"RealEngine/vendor/spdlog/include",
		"RealEngine/src",
		"RealEngine/vendor",
		"%{IncludeDir.glm}"
	}
	links{
		"RealEngine"
	}
	filter "system:windows"
		systemversion "latest"

		defines
		{
			"RE_PLATFORM_WINDOWS",
			"_SILENCE_STDEXT_ARR_ITERS_DEPRECATION_WARNING"
		}

		 

	filter "configurations:Debug"
		defines "RE_DEBUG"
		runtime "Debug"
		symbols "on"
		links
		{
			"RealEngine/vendor/assimp/bin/Debug/assimp-vc141-mtd.lib"
		}

	filter "configurations:Release"
		defines "RE_RELEASE"
		runtime "Release"
		optimize "on"
		links
		{
			"RealEngine/vendor/assimp/bin/Release/assimp-vc141-mt.lib"
		}

	filter "configurations:Dist"
		defines "RE_DIST"
		runtime "Release"
		optimize "on"
		links
		{
			"RealEngine/vendor/assimp/bin/Release/assimp-vc141-mt.lib"
		}

	