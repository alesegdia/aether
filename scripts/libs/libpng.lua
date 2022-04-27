copyFile(path.join(AETHER_DIR, "module/libpng/scripts/pnglibconf.h.prebuilt"), path.join(AETHER_DIR, "module/libpng/pnglibconf.h"))

commonLibSetup("libpng")

	configuration {}
	
	includedirs {
		path.join(AETHER_DIR, "module/libpng/"),
		path.join(AETHER_DIR, "module/zlib/"),
	}

	files {
		path.join(AETHER_DIR, "module/libpng/png.c"),
		path.join(AETHER_DIR, "module/libpng/pngerror.c"),
		path.join(AETHER_DIR, "module/libpng/pngget.c"),
		path.join(AETHER_DIR, "module/libpng/pngmem.c"),
		path.join(AETHER_DIR, "module/libpng/pngread.c"),
		path.join(AETHER_DIR, "module/libpng/pngpread.c"),
		path.join(AETHER_DIR, "module/libpng/pngrio.c"),
		path.join(AETHER_DIR, "module/libpng/pngrtran.c"),
		path.join(AETHER_DIR, "module/libpng/pngrutil.c"),
		path.join(AETHER_DIR, "module/libpng/pngset.c"),
		path.join(AETHER_DIR, "module/libpng/pngtrans.c"),
		path.join(AETHER_DIR, "module/libpng/pngwio.c"),
		path.join(AETHER_DIR, "module/libpng/pngwrite.c"),
		path.join(AETHER_DIR, "module/libpng/pngwtran.c"),
		path.join(AETHER_DIR, "module/libpng/pngwutil.c"),

		-- PRIVATE HEADERS
		path.join(AETHER_DIR, "module/libpng/pngpriv.h"),
		path.join(AETHER_DIR, "module/libpng/pngdebug.h"),
		path.join(AETHER_DIR, "module/libpng/pnginfo.h"),
		path.join(AETHER_DIR, "module/libpng/pngstruct.h"),

		-- PUBLIC HEADERS
		path.join(AETHER_DIR, "module/libpng/png.h"),
		path.join(AETHER_DIR, "module/libpng/pngconf.h"),
		path.join(AETHER_DIR, "module/libpng/pnglibconf.h"),
	}
