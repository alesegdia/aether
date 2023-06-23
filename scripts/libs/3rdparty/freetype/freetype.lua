externalCommonLibSetup("freetype", true)

	configuration {}
	
	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "freetype/include"),
	}

	defines {
		"FT2_BUILD_LIBRARY",
	}

	files {
		path.join(AETHER_EXTERNALS_DIR, "freetype/include/**.h"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/autofit/autofit.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftbase.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftbbox.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftbdf.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftbitmap.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftcid.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftfstype.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftgasp.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftglyph.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftgxval.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftinit.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftmm.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftotval.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftpatent.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftpfr.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftstroke.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftsynth.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftsystem.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/fttype1.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/base/ftwinfnt.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/bdf/bdf.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/cache/ftcache.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/cff/cff.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/cid/type1cid.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/gzip/ftgzip.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/lzw/ftlzw.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/pcf/pcf.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/pfr/pfr.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/psaux/psaux.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/pshinter/pshinter.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/psnames/psmodule.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/raster/raster.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/sfnt/sfnt.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/smooth/smooth.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/truetype/truetype.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/type1/type1.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/type42/type42.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/winfonts/winfnt.c"),
		path.join(AETHER_EXTERNALS_DIR, "freetype/src/winfonts/winfnt.c"),
	}

	configuration { "linux*" }
		files {
		}

	configuration { "windows" }
		files {
			path.join(AETHER_EXTERNALS_DIR, "freetype/builds/windows/ftdebug.c"),
		}

	configuration {}
