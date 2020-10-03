project "sdl-image"
	location "../build"
	kind "StaticLib"
	language "C++"

	configuration {}

	includedirs {
		path.join(AETHER_DIR, "module/sdl-image"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37"),
		path.join(AETHER_DIR, "module/sdl/include"),
	}

	files {
		path.join(AETHER_DIR, "module/sdl-image/SDL_image.h"),
		path.join(AETHER_DIR, "module/sdl-image/IMG.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_png.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/png.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngerror.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngget.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngmem.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngread.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngpread.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngrio.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngrtran.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngrutil.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngset.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngtrans.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngwio.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngwrite.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngwtran.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngwutil.c"),

		-- PRIVATE HEADERS
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngpriv.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngdebug.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pnginfo.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngstruct.h"),

		-- PUBLIC HEADERS
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/png.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pngconf.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37/pnglibconf.h"),

	}

	files {
		
	}

	configuration { "vs20*" } 
		defines {
			"CRT_SECURE_NO_DEPRECATE"
		}

		configuration {}