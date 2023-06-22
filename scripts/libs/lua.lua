externalCommonLibSetup("lua", true)
	language "C"
	configuration {}
	
	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "lua/"),
	}

	files {
		path.join(AETHER_EXTERNALS_DIR, "lua/l*.h"),
		path.join(AETHER_EXTERNALS_DIR, "lua/l*.c"),
	}
