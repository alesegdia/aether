externalCommonLibSetup("zlib")

	configuration {}
	
	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "zlib/"),
	}

	files {
		-- PUBLIC HEADERS
		path.join(AETHER_EXTERNALS_DIR, "zlib/zconf.h"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/zlib.h"),

		-- PRIVATE HEADERS
		path.join(AETHER_EXTERNALS_DIR, "zlib/crc32.h"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/deflate.h"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/gzguts.h"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/inffast.h"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/inffixed.h"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/infflate.h"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/inftrees.h"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/trees.h"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/zutil.h"),

		-- SOURCES
		path.join(AETHER_EXTERNALS_DIR, "zlib/adler32.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/compress.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/crc32.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/deflate.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/gzclose.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/gzlib.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/gzread.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/gzwrite.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/inflate.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/infback.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/inftrees.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/inffast.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/trees.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/uncompr.c"),
		path.join(AETHER_EXTERNALS_DIR, "zlib/zutil.c"),
	}

