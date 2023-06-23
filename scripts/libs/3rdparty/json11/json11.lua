externalCommonLibSetup("json11", true)
	language "C++"
	configuration {}
	
	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "json11"),
	}

	files {
		path.join(AETHER_EXTERNALS_DIR, "json11/json11.hpp"),
		path.join(AETHER_EXTERNALS_DIR, "json11/json11.cpp"),
	}
