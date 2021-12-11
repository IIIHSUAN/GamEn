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

myIncludeDir = {}
myIncludeDir["GLFW"] = "GamEn/module/GLFW/include"
myIncludeDir["Glad"] = "GamEn/module/Glad/include"

include "GamEn/module/GLFW"  --GLFW project
include "GamEn/module/Glad"  --Glad project

project "GamEn"
    location "GamEn"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-tmp/" .. outputdir .. "/%{prj.name}")

    pchheader "GE_pch.h"
    pchsource "GamEn/src/GE_pch.cpp"  -- tell VS compiler only

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }
    includedirs
    {
        "%{prj.name}/module/spdlog/include",
        "%{prj.name}/src",
        "%{myIncludeDir.GLFW}",
        "%{myIncludeDir.Glad}"
    }
    links
    {
        "GLFW",
        "Glad",
        "opengl32.lib"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "on"
        systemversion "latest"
        defines
        {
            "GE_PLATFORM_WIN",
            "GE_BUILD_DLL"
        }
        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Tester")
        }

    filter "configurations:Debug"
        defines "GE_DEBUG"
        buildoptions "/MDd"
        symbols "on"
    filter "configurations:Release"
        defines "GE_Release"
        buildoptions "/MD"
        optimize "on"
    filter "configurations:Distribute"
        defines "GE_Distribute"
        buildoptions "/MD"
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
        "%{wks.location}/GamEn/module/spdlog/include",
        "%{wks.location}/GamEn/src"
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
        buildoptions "/MDd"
        symbols "on"
    filter "configurations:Release"
        defines "GE_Release"
        buildoptions "/MD"
        optimize "on"
    filter "configurations:Distribute"
        defines "GE_Distribute"
        buildoptions "/MD"
        optimize "on"