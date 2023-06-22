copyFile(path.join(AETHER_EXTERNALS_DIR, "libpng/scripts/pnglibconf.h.prebuilt"), path.join(AETHER_EXTERNALS_DIR, "libpng/pnglibconf.h"))

externalCommonLibSetup("libpng", true)

	configuration {}
	
	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "libpng/"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/"),
	}

	files {
		path.join(AETHER_EXTERNALS_DIR, "libpng/png.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngerror.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngget.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngmem.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngread.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngpread.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngrio.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngrtran.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngrutil.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngset.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngtrans.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngwio.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngwrite.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngwtran.c"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngwutil.c"),

		-- PRIVATE HEADERS
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngpriv.h"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngdebug.h"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pnginfo.h"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngstruct.h"),

		-- PUBLIC HEADERS
		path.join(AETHER_EXTERNALS_DIR, "libpng/png.h"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pngconf.h"),
		path.join(AETHER_EXTERNALS_DIR, "libpng/pnglibconf.h"),
	}
