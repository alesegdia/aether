externalCommonLibSetup("tinyxml2", true)
	language "C++"

	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "tinyxml2"),
	}

	files {
		path.join(AETHER_EXTERNALS_DIR, "tinyxml2/tinyxml2.h"),
		path.join(AETHER_EXTERNALS_DIR, "tinyxml2/tinyxml2.cpp"),
	}



