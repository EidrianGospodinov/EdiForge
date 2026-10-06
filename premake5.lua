workspace "EdiForge"
	architecture "x64"

	configurations {"Debug","Release", "Dist"}


outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "EdiForge"

	location "EdiForge"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++20"
		staticruntime  "On"
		systemversion "latest"


		defines
		{
			"EF_BUILD_DLL",
			"EF_Platform_Windows"
		}

	postbuildcommands
		{
			("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
	filter "configurations:Debug"
		defines "EF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EF_DIST"
		optimize "On"




project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"

	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"EdiForge/vendor/spdlog/include",
		"EdiForge/src"
	}

	links
	{
		"EdiForge"
	}
	filter "system:windows"
		cppdialect "C++20"
		staticruntime  "On"
		systemversion "latest"


		defines
		{
			"EF_Platform_Windows"
		}

	
	filter "configurations:Debug"
		defines "EF_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "EF_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "EF_DIST"
		optimize "On"
