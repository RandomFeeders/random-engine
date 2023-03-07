project "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")
	objdir ("%{wks.location}/Intermediates/" .. outputdir .. "/%{prj.name}")

	files
	{
		"src/**.h",
		"src/**.cpp",
		"assets/**"
	}

	includedirs
	{
		"%{wks.location}/Sandbox",
		"%{wks.location}/RandomEngine/vendor/spdlog/include",
		"%{wks.location}/RandomEngine/src",
		"%{wks.location}/RandomEngine/vendor",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.VulkanSDK}"
	}

	links
	{
		"RandomEngine"
	}

	fontsfolder = "%{wks.location}/RandomEngine/vendor/Fonts"

	postbuildcommands {
		("{COPYDIR} \"" .. fontsfolder .. "/*.ttf\" \"%{cfg.targetdir}/fonts\"")
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "RE_ENV_DEBUG"
		runtime "Debug"
		symbols "on"
		debugdir ("%{wks.location}/Binaries/" .. outputdir .. "/%{prj.name}")

	filter "configurations:Release"
		defines "RE_ENV_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "RE_ENV_DIST"
		runtime "Release"
		optimize "on"
