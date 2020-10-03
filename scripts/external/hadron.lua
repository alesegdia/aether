project "hadron"
	location "../build"
	kind "StaticLib"
	language "C++"

	configuration {}

	includedirs {
		path.join(AETHER_DIR, "module/hadron/src/lib"),
	}

	files {
		path.join(AETHER_DIR, "module/hadron/src/lib/**.h"),
		path.join(AETHER_DIR, "module/hadron/src/lib/**.cpp"),
	}
