
dofile("sdl-files.lua")

commonLibSetup("sdl")

	includedirs {
		SDL_INCLUDE_DIRS
	}

	files {
		SDL_COMMON_SOURCES
	}

	configuration { "linux*" }
		files {
			SDL_LINUX_SOURCES
		}

	configuration { "vs20*" }
		files {
			SDL_WIN_SOURCES
		}
		defines {
			"SDL_VIDEO_DRIVER_DUMMY",
			"SDL_AUDIO_DRIVER_DUMMY",
		}
		defines {
			"HAVE_LIBC",
		}

	configuration { "mingw*" }
		files {
			SDL_MINGW_SOURCES
		}

