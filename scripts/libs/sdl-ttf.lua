commonLibSetup("sdl-ttf")

	includedirs {
		path.join(AETHER_DIR, "module/sdl-ttf"),
		path.join(AETHER_DIR, "module/freetype/include"),
		path.join(AETHER_DIR, "module/sdl/include"),
	}

	files {
		path.join(AETHER_DIR, "module/sdl-ttf/SDL_ttf.h"),
		path.join(AETHER_DIR, "module/sdl-ttf/SDL_ttf.c"),
	}

