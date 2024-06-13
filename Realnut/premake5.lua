project "Realnut"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "off"

	targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp"
	}

	includedirs
	{
		"%{wks.location}/RealEngine/vendor/spdlog/include",
		"%{wks.location}/RealEngine/src",
		"%{wks.location}/RealEngine/vendor",
		"%{IncludeDir.glm}",
		"%{IncludeDir.entt}",
		"%{IncludeDir.ImGuizmo}",
		"%{IncludeDir.yaml_cpp}"
	}

	links
	{
		"RealEngine"
	}

	filter "system:windows"
		systemversion "latest"

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