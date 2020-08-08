
-- Workspace: AutoGame
-- -------------------
workspace "AutoGame"
	architecture "x86_64"
	configurations { "Debug", "Release" }

-- Project: AutoGame
-- -----------------
	project "AutoGame"
		location "AutoGame"
		kind "ConsoleApp"
		language "C++"
		cppdialect "c++17"
		staticruntime "On"

		targetdir "Bin/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"
		objdir "Bin-Int/%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}/%{prj.name}"

		pchheader "AgPch.h"
		pchsource "%{prj.name}/Src/AgPch.cpp"

		files {
			"%{prj.name}/Src/**.cpp",
			"%{prj.name}/Src/**.h"
		}

		includedirs {
			"%{prj.name}/Src"
		}

		filter "system:windows"
			defines "AG_PLAT_WINDOWS"
			systemversion "latest"

		filter "configurations:Debug"
			defines "AG_BUILD_DEBUG"
			symbols "Full"
			optimize "Off"

		filter "configurations:Release"
			defines "AG_BUILD_RELEASE"
			symbols "Off"
			optimize "Full"