commonLibSetup("json11")
	language "C++"
	configuration {}
	
	includedirs {
		path.join(AETHER_DIR, "module/json11"),
	}

	files {
		path.join(AETHER_DIR, "module/json11/json11.hpp"),
		path.join(AETHER_DIR, "module/json11/json11.cpp"),
	}
