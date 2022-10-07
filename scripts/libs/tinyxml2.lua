commonLibSetup("tinyxml2", true)
	language "C++"

	includedirs {
		path.join(AETHER_DIR, "module/tinyxml2"),
	}

	files {
		path.join(AETHER_DIR, "module/tinyxml2/tinyxml2.h"),
		path.join(AETHER_DIR, "module/tinyxml2/tinyxml2.cpp"),
	}



