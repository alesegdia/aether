commonLibSetup("lua")
	language "C"
	configuration {}
	
	includedirs {
		path.join(AETHER_DIR, "module/lua/"),
	}

	files {
		path.join(AETHER_DIR, "module/lua/l*.h"),
		path.join(AETHER_DIR, "module/lua/l*.c"),
	}
