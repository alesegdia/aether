commonLibSetup("zlib")

	configuration {}
	
	includedirs {
		path.join(AETHER_DIR, "module/zlib/"),
	}

	files {
		-- PUBLIC HEADERS
		path.join(AETHER_DIR, "module/zlib/zconf.h"),
		path.join(AETHER_DIR, "module/zlib/zlib.h"),

		-- PRIVATE HEADERS
		path.join(AETHER_DIR, "module/zlib/crc32.h"),
		path.join(AETHER_DIR, "module/zlib/deflate.h"),
		path.join(AETHER_DIR, "module/zlib/gzguts.h"),
		path.join(AETHER_DIR, "module/zlib/inffast.h"),
		path.join(AETHER_DIR, "module/zlib/inffixed.h"),
		path.join(AETHER_DIR, "module/zlib/infflate.h"),
		path.join(AETHER_DIR, "module/zlib/inftrees.h"),
		path.join(AETHER_DIR, "module/zlib/trees.h"),
		path.join(AETHER_DIR, "module/zlib/zutil.h"),

		-- SOURCES
		path.join(AETHER_DIR, "module/zlib/adler32.c"),
		path.join(AETHER_DIR, "module/zlib/compress.c"),
		path.join(AETHER_DIR, "module/zlib/crc32.c"),
		path.join(AETHER_DIR, "module/zlib/deflate.c"),
		path.join(AETHER_DIR, "module/zlib/gzclose.c"),
		path.join(AETHER_DIR, "module/zlib/gzlib.c"),
		path.join(AETHER_DIR, "module/zlib/gzread.c"),
		path.join(AETHER_DIR, "module/zlib/gzwrite.c"),
		path.join(AETHER_DIR, "module/zlib/inflate.c"),
		path.join(AETHER_DIR, "module/zlib/infback.c"),
		path.join(AETHER_DIR, "module/zlib/inftrees.c"),
		path.join(AETHER_DIR, "module/zlib/inffast.c"),
		path.join(AETHER_DIR, "module/zlib/trees.c"),
		path.join(AETHER_DIR, "module/zlib/uncompr.c"),
		path.join(AETHER_DIR, "module/zlib/zutil.c"),
	}

