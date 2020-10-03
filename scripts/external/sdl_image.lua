project "sdl-image"
	location "../build"
	kind "StaticLib"
	language "C++"

	configuration {}
	
	defines {
		"LOAD_PNG",
	}
	
	includedirs {
		path.join(AETHER_DIR, "module/sdl-image"),
		path.join(AETHER_DIR, "module/sdl-image/external/libpng-1.6.37"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11"),
		path.join(AETHER_DIR, "module/sdl/include"),
	}

	-- SDL_image
	files {
		path.join(AETHER_DIR, "module/sdl-image/SDL_image.h"),
		path.join(AETHER_DIR, "module/sdl-image/IMG.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_png.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_bmp.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_gif.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_jpg.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_lbm.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_pcx.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_pnm.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_svg.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_tga.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_tif.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_webp.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_xcf.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_xpm.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_xv.c"),
		path.join(AETHER_DIR, "module/sdl-image/IMG_xxx.c"),
	}

	-- libpng
	files {
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

	-- zlib
	files {
		-- PUBLIC HEADERS
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/zconf.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/zlib.h"),

		-- PRIVATE HEADERS
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/crc32.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/deflate.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/gzguts.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/inffast.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/inffixed.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/infflate.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/inftrees.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/trees.h"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/zutil.h"),

		-- SOURCES
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/adler32.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/compress.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/crc32.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/deflate.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/gzclose.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/gzlib.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/gzread.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/gzwrite.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/inflate.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/infback.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/inftrees.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/inffast.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/trees.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/uncompr.c"),
		path.join(AETHER_DIR, "module/sdl-image/external/zlib-1.2.11/zutil.c"),
	}

	configuration { "vs20*" } 
		defines {
			"CRT_SECURE_NO_DEPRECATE"
		}

		configuration {}