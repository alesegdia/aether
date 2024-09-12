dofile(path.join(AETHER_GENIE_PLUGINS_DIR, "aether/aether-files.lua"))
dofile("common.lua")


function aetherGameLib(projectName)
	project (projectName)
	kind "SharedLib"
	language "C++"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }
	flags{ "CppLatest" }
	configuration {}
		links { AETHER_COMMON_LIBS }
		includedirs { AETHER_COMMON_INCLUDE_DIRS }

	configSDL()
	configAllegro(false)
	configRaylib()
	configGL()
	commonFlags()
end

function aetherProject(projectName)
	project (projectName)
	kind "ConsoleApp"
	language "C++"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }

	flags{ "CppLatest" }

	configuration {}
		links { AETHER_COMMON_LIBS }
		includedirs {
			AETHER_COMMON_INCLUDE_DIRS,
			path.join(AETHER_EXTERNALS_DIR, "L2DFileDialog/"),
		}			

	-- https://support.microsoft.com/es-es/help/154753/description-of-the-default-c-and-c-libraries-that-a-program-will-link
	configuration { "vs20*", "debug" }
		links { "LIBCMTD" }

	configuration { "vs20*", "release" }
		links { "LIBCMT" }

	configSDL()
	configAllegro(true)
	configRaylib()
	configGL()


	commonFlags()
end

function aetherServerProject(projectName)
	project (projectName)
	kind "ConsoleApp"
	language "C++"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }

	flags{ "CppLatest" }

	debugdir ("..")
	targetdir ("../build")

	configuration {}
		links { 
			"enet",
			"user32",
			"gdi32",
			"comdlg32",
			"ole32",
			"winmm",
			"kernel32",
			"psapi",
			"shlwapi",
			"ws2_32",		
		}
		includedirs {
			path.join(AETHER_EXTERNALS_DIR, "enet/include"),
		}			

end

function defineProject(projectName)
	solution(projectName)
	startproject(projectName .. "-game")
	location "../build/"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }
	language "C++"
	aetherBuild()
end

function defineGameTarget(targetName, dll)
	if dll == true then
		aetherGameLib(targetName .. "-game")
	else
		aetherProject(targetName .. "-game-bin")
	end

	debugdir ("..")
	targetdir ("../build")
	if dll == false then
		files {
			path.join(AETHER_DIR, "src/main/main.cpp")
		}
	end
end

function defineGameTargetExecutable(targetName)
	group("executable")
	defineGameTarget(targetName, false)
end

function defineGameTargetDLL(targetName)
	group("library")
	defineGameTarget(targetName, true)
end

