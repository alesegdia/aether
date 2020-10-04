dofile(path.join(AETHER_DIR, "scripts/external/sdl.lua"))
	targetdir ("../build")
	flags {
		"Symbols",
		"StaticRuntime"
	}
	
dofile(path.join(AETHER_DIR, "scripts/external/sdl_ttf.lua"))
	targetdir ("../build")
	flags {
		"Symbols",
		"StaticRuntime"
	}
	
dofile(path.join(AETHER_DIR, "scripts/external/sdl_image.lua"))
	targetdir ("../build")
	flags {
		"Symbols",
		"StaticRuntime"
	}
	
