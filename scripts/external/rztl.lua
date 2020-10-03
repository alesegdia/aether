project "rztl"
	location "../build"
	kind "StaticLib"
	language "C++"

	configuration {}

	includedirs {
		path.join(AETHER_DIR, "module/rztl/include"),
	}

	files {
		path.join(AETHER_DIR, "module/rztl/include/**.h"),
	}
