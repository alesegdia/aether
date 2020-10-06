dofile("../libs/aether-files.lua")
dofile("common.lua")

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

	configuration { "backend-sdl" }
		defines { "AETHER_USE_SDL" }
		includedirs { AETHER_SDL_INCLUDE_DIRS }
		links { AETHER_SDL_COMMON_LIBS }

	configuration { "backend-allegro" }
		defines { "AETHER_USE_ALLEGRO", "ALEGRO_STATICLINK" }
		includedirs { AETHER_ALLEGRO_INCLUDE_DIRS }
		links { AETHER_ALLEGRO_COMMON_LIBS }

	configuration { "vs20*", "backend-sdl" }
		links { AETHER_SDL_WIN_LIBS }
		--flags { "WinMain" }

	configuration { "vs20*", "backend-allegro" }
        links { AETHER_ALLEGRO_WIN_LIBS }

	commonFlags()
end
