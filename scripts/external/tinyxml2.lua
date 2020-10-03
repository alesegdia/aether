project "tinyxml2"
	location "../build"
	kind "StaticLib"
	language "C++"

	configuration {}
	
	includedirs {
		path.join(AETHER_DIR, "module/tinyxml2"),
	}

	files {
		path.join(AETHER_DIR, "module/tinyxml2/tinyxml2.h"),
		path.join(AETHER_DIR, "module/tinyxml2/tinyxml2.cpp"),
	}

