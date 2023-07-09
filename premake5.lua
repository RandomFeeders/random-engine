include "./Vendor/Premake/premake_customization/solution_items.lua"
include "dependencies.lua"

workspace "Random Engine"
	architecture "x86_64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	solution_items
	{
		".editorconfig",
		".gitignore",
		".gitmodules",
		"README.md",
		"LICENSE.md"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

group "Dependencies"
	include "Vendor/Premake"
	include "RandomEngine/vendor/GLFW"
	include "RandomEngine/vendor/Glad"
	include "RandomEngine/vendor/imgui"
	include "RandomEngine/vendor/Spdlog"
	include "RandomEngine/vendor/fmt"
	
group ""
	include "RandomEngine"
	include "Sandbox"
	include "AssetManager"
