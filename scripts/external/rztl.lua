commonLibSetup("rztl")

	configuration {}
	
	includedirs {
		path.join(AETHER_DIR, "module/rztl/include"),
	}

	dofile(path.join(AETHER_DIR, "scripts/common-flags.lua"))

	files {
		path.join(AETHER_DIR, "module/rztl/include/**.h"),
	}
