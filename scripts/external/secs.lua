project "secs"
	location "../build"
	kind "StaticLib"
	language "C++"

	configuration {}

	includedirs {
		path.join(AETHER_DIR, "module/secs/src/lib"),
	}

	files {
		path.join(AETHER_DIR, "module/secs/src/lib/**.h"),
		path.join(AETHER_DIR, "module/secs/src/lib/**.cpp"),
	}
