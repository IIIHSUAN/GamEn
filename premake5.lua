-- ref:https://github.com/premake/premake-core/wiki

workspace "GamEn"  -- solution
	architecture "x64"
	configurations
	{
		"Debug",
		"Release",
		"Distribute"
	}

outputdir = "%{cfg.system}-%{cfg.architecture}-%{cfg.buildcfg}"

project "GamEn"
	location "GamEn"
	kind "SharedLib"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-tmp/" .. outputdir .. "/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"%{prj.name}/module/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"
		defines
		{
			"GE_PLATFORM_WIN",
			"GE_BUILD_DLL"
			-- _WINDLL;_UNICODE;UNICODE;
		}
		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Tester")
		}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		symbols "on"
	filter "configurations:Release"
		defines "GE_Release"
		optimize "on"
	filter "configurations:Distribute"
		defines "GE_Distribute"
		optimize "on"


project "Tester"
	location "Tester"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-tmp/" .. outputdir .. "/%{prj.name}")
	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	includedirs
	{
		"GamEn/module/spdlog/include",
		"GamEn/src"
	}
	links  -- find lib
	{
		"GamEn"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"
		defines
		{
			"GE_PLATFORM_WIN"
			-- _WINDLL;_UNICODE;UNICODE;
		}

	filter "configurations:Debug"
		defines "GE_DEBUG"
		symbols "on"
	filter "configurations:Release"
		defines "GE_Release"
		optimize "on"
	filter "configurations:Distribute"
		defines "GE_Distribute"
		optimize "on"