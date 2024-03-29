externalCommonLibSetup("sdl-image")

	configuration {}
	
	defines {
		"LOAD_PNG",
	}
	
	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "sdl-image"),
		path.join(AETHER_EXTERNALS_DIR, "libpng"),
		path.join(AETHER_EXTERNALS_DIR, "zlib"),
		path.join(AETHER_EXTERNALS_DIR, "sdl/include"),
	}

	-- SDL_image
	files {
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/SDL_image.h"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_png.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_bmp.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_gif.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_jpg.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_lbm.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_pcx.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_pnm.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_svg.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_tga.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_tif.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_webp.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_xcf.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_xpm.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_xv.c"),
		path.join(AETHER_EXTERNALS_DIR, "sdl-image/IMG_xxx.c"),
	}

	configuration { "vs20*" } 
		defines {
			"CRT_SECURE_NO_DEPRECATE"
		}

	configuration {}