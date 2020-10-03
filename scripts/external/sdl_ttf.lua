project "sdl-ttf"
	location "../build"
	kind "StaticLib"
	language "C++"

	configuration {}

	includedirs {
		path.join(AETHER_DIR, "module/sdl-ttf"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/include"),
		path.join(AETHER_DIR, "module/sdl/include"),
	}

	defines {
		"FT2_BUILD_LIBRARY",
	}

	configuration {}

	files {
		path.join(AETHER_DIR, "module/sdl-ttf/SDL_ttf.h"),
		path.join(AETHER_DIR, "module/sdl-ttf/SDL_ttf.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/include/**.h"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/autofit/autofit.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftbase.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftbbox.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftbdf.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftbitmap.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftcid.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftfstype.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftgasp.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftglyph.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftgxval.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftinit.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftmm.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftotval.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftpatent.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftpfr.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftstroke.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftsynth.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftsystem.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/fttype1.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/base/ftwinfnt.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/bdf/bdf.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/cache/ftcache.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/cff/cff.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/cid/type1cid.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/gzip/ftgzip.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/lzw/ftlzw.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/pcf/pcf.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/pfr/pfr.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/psaux/psaux.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/pshinter/pshinter.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/psnames/psmodule.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/raster/raster.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/sfnt/sfnt.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/smooth/smooth.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/truetype/truetype.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/type1/type1.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/type42/type42.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/winfonts/winfnt.c"),
		path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/src/winfonts/winfnt.c"),
	}

	configuration { "linux*" }
		files {
		}

	configuration { "vs20*" }
		files {
			path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/builds/windows/ftdebug.c"),
		}

	configuration { "mingw*" }
		files {
			path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/builds/windows/ftdebug.c"),
		}
		
	configuration {}
