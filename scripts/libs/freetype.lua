commonLibSetup("freetype", true)

	configuration {}
	
	includedirs {
		path.join(AETHER_DIR, "module/freetype/include"),
	}

	defines {
		"FT2_BUILD_LIBRARY",
	}

	files {
		path.join(AETHER_DIR, "module/freetype/include/**.h"),
		path.join(AETHER_DIR, "module/freetype/src/autofit/autofit.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftbase.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftbbox.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftbdf.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftbitmap.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftcid.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftfstype.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftgasp.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftglyph.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftgxval.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftinit.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftmm.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftotval.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftpatent.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftpfr.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftstroke.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftsynth.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftsystem.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/fttype1.c"),
		path.join(AETHER_DIR, "module/freetype/src/base/ftwinfnt.c"),
		path.join(AETHER_DIR, "module/freetype/src/bdf/bdf.c"),
		path.join(AETHER_DIR, "module/freetype/src/cache/ftcache.c"),
		path.join(AETHER_DIR, "module/freetype/src/cff/cff.c"),
		path.join(AETHER_DIR, "module/freetype/src/cid/type1cid.c"),
		path.join(AETHER_DIR, "module/freetype/src/gzip/ftgzip.c"),
		path.join(AETHER_DIR, "module/freetype/src/lzw/ftlzw.c"),
		path.join(AETHER_DIR, "module/freetype/src/pcf/pcf.c"),
		path.join(AETHER_DIR, "module/freetype/src/pfr/pfr.c"),
		path.join(AETHER_DIR, "module/freetype/src/psaux/psaux.c"),
		path.join(AETHER_DIR, "module/freetype/src/pshinter/pshinter.c"),
		path.join(AETHER_DIR, "module/freetype/src/psnames/psmodule.c"),
		path.join(AETHER_DIR, "module/freetype/src/raster/raster.c"),
		path.join(AETHER_DIR, "module/freetype/src/sfnt/sfnt.c"),
		path.join(AETHER_DIR, "module/freetype/src/smooth/smooth.c"),
		path.join(AETHER_DIR, "module/freetype/src/truetype/truetype.c"),
		path.join(AETHER_DIR, "module/freetype/src/type1/type1.c"),
		path.join(AETHER_DIR, "module/freetype/src/type42/type42.c"),
		path.join(AETHER_DIR, "module/freetype/src/winfonts/winfnt.c"),
		path.join(AETHER_DIR, "module/freetype/src/winfonts/winfnt.c"),
	}

	configuration { "linux*" }
		files {
		}

	configuration { "windows" }
		files {
			path.join(AETHER_DIR, "module/freetype/builds/windows/ftdebug.c"),
		}

	configuration {}
