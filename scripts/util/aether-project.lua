dofile("../libs/aether-files.lua")
dofile("common.lua")


function aetherGameLib(projectName)
	project (projectName)
	kind "SharedLib"
	language "C++"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }

	configuration {}
		links { AETHER_COMMON_LIBS }
		includedirs { AETHER_COMMON_INCLUDE_DIRS }

	configSDL()
	configAllegro(false)
	commonFlags()
end

function aetherProject(projectName)
	project (projectName)
	kind "ConsoleApp"
	language "C++"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }

	configuration {}
		links { AETHER_COMMON_LIBS }
		includedirs { AETHER_COMMON_INCLUDE_DIRS }

	-- https://support.microsoft.com/es-es/help/154753/description-of-the-default-c-and-c-libraries-that-a-program-will-link
	configuration { "vs20*", "debug" }
		links { "LIBCMTD" }

	configuration { "vs20*", "release" }
		links { "LIBCMT" }

	configSDL()
	configAllegro(true)

	commonFlags()
end
