project "tmxparser"
	location "../build"
	kind "StaticLib"
	language "C++"

	configuration {}

	includedirs {
		path.join(AETHER_DIR, "module/tmxparser/include"),
		path.join(AETHER_DIR, "module/tinyxml2"),
	}

	links {
		"tinyxml2"
	}

	files {
		path.join(AETHER_DIR, "module/tmxparser/include/**.h"),
		path.join(AETHER_DIR, "module/tmxparser/src/**.cpp"),
		path.join(AETHER_DIR, "module/tmxparser/src/**.c"),
	}

	os.copyfile(
		path.join(AETHER_DIR, "module/tmxparser/include/Tmx.h.in"),
		path.join(AETHER_DIR, "module/tmxparser/include/Tmx.h"))

	defines {
		"USE_MINIZ"
	}