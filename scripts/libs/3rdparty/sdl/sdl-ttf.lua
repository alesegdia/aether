externalCommonLibSetup("sdl-ttf")

	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "sdl-ttf"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/include"),
		path.join(AETHER_EXTERNALS_DIR, "sdl/include"),
	}

	files {
		path.join(AETHER_EXTERNALS_DIR, "sdl-ttf/SDL_ttf.h"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-ttf/SDL_ttf.c"),
	}

