pluginCommonLibSetup("secs")
	language "C++"
	includedirs {
		path.join(AETHER_PLUGINS_DIR, "secs/src/lib"),
	}

	files {
		path.join(AETHER_PLUGINS_DIR, "secs/src/lib/**.h"),
		path.join(AETHER_PLUGINS_DIR, "secs/src/lib/**.cpp"),
	}
