pluginCommonLibSetup("hadron")
	language "C++"
	configuration {}
	
	includedirs {
		path.join(AETHER_PLUGINS_DIR, "hadron/src/lib"),
	}

	files {
		path.join(AETHER_PLUGINS_DIR, "hadron/src/lib/**.h"),
		path.join(AETHER_PLUGINS_DIR, "hadron/src/lib/**.cpp"),
	}
