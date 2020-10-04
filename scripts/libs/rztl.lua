commonLibSetup("rztl")

	configuration {}
	
	includedirs {
		path.join(AETHER_DIR, "module/rztl/include"),
	}

	files {
		path.join(AETHER_DIR, "module/rztl/include/**.h"),
	}
