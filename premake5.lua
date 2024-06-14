include "./vendor/premake/premake_customization/solution_items.lua"
include "Dependencies.lua"
workspace "RealEngine"
	architecture "x86_64"
	startproject "Realnut"
	configurations{
		"Debug",
		"Release",
		"Dist"
	}
	solution_items
	{
		".editorconfig"
	}

	flags
	{
		"MultiProcessorCompile"
	}
outputdir="%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


group "Dependencies"
	include "vendor/premake"
	include "RealEngine/vendor/box2d"
	include "RealEngine/vendor/GLFW"
	include "RealEngine/vendor/Glad"
	include "RealEngine/vendor/imgui"
	include "RealEngine/vendor/yaml-cpp"
group ""


group "Core"
	include "RealEngine"
	include "Real-ScriptCore"
group ""

group "Tools"
	include "Realnut"
group ""

group "Misc"
	include "Sandbox"
group ""