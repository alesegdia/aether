pluginCommonLibSetup("rztl")
	language "C++"

	configuration {}
	
	includedirs {
		path.join(AETHER_PLUGINS_DIR, "rztl/include"),
	}

	files {
		path.join(AETHER_PLUGINS_DIR, "rztl/include/**.h"),
	}
