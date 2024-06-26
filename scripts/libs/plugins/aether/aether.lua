dofile("aether-files.lua")

pluginCommonLibSetup("aether")
	language "C++"
	targetdir (path.join(AETHER_DIR, "/bin/lib"))
	flags { "CppLatest" }
	includedirs { AETHER_COMMON_INCLUDE_DIRS, AETHER_API_INCLUDE_DIRS }
	files { AETHER_COMMON_SOURCES, AETHER_API_SOURCES }

	configuration { "backend-allegro" }
		defines {
			"AETHER_USE_ALLEGRO",
			"ALLEGRO_STATICLINK",
        	"ALLEGRO_USE_SDL",
        	"ALLEGRO_CFG_D3D",
		}
		files {
			AETHER_ALLEGRO_CORE_SOURCES,
			AETHER_ALLEGRO_GRAPHICS_SOURCES,
			AETHER_ALLEGRO_AUDIO_SOURCES,
		}
		includedirs {
			AETHER_ALLEGRO_INCLUDE_DIRS
		}

	configuration { "backend-sdl" }
		defines { "AETHER_USE_SDL" }
		files {
			AETHER_SDL_CORE_SOURCES,
			AETHER_SDL_GRAPHICS_SOURCES,
		}
		includedirs {
			AETHER_SDL_INCLUDE_DIRS
		}

	configuration { "backend-gl" }
		defines { "AETHER_USE_GL" }
		files {
			AETHER_GL_CORE_SOURCES,
			AETHER_GL_GRAPHICS_SOURCES,
		}
		includedirs {
			AETHER_GL_INCLUDE_DIRS
		}

	configuration { "backend-raylib" }
		defines {"AETHER_USE_RAYLIB"}
		files {
			AETHER_RAYLIB_SOURCES
		}
		includedirs {
			AETHER_RAYLIB_INCLUDE_DIRS
		}

	configuration { "disable-audio" }
		files { AETHER_DUMMY_AUDIO_SOURCES }

	configuration { "enable-audio" }	
		defines { "AETHER_ENABLE_AUDIO" }

	configuration { "backend-sdl", "enable-audio" }
		files { AETHER_SDL_AUDIO_SOURCES }

