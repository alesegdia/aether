externalCommonLibSetup("tmxparser", true)
	language "C++"
	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "tmxparser/include"),
		path.join(AETHER_EXTERNALS_DIR, "tinyxml2"),
	}

	files {
		path.join(AETHER_EXTERNALS_DIR, "tmxparser/include/**.h"),
		path.join(AETHER_EXTERNALS_DIR, "tmxparser/src/**.cpp"),
		path.join(AETHER_EXTERNALS_DIR, "tmxparser/src/**.c"),
	}

	os.copyfile(
		path.join(AETHER_EXTERNALS_DIR, "tmxparser/include/Tmx.h.in"),
		path.join(AETHER_EXTERNALS_DIR, "tmxparser/include/Tmx.h"))

	defines {
		"USE_MINIZ"
	}