commonLibSetup("hadron")

	configuration {}
	
	includedirs {
		path.join(AETHER_DIR, "module/hadron/src/lib"),
	}

	dofile(path.join(AETHER_DIR, "scripts/common-flags.lua"))

	files {
		path.join(AETHER_DIR, "module/hadron/src/lib/**.h"),
		path.join(AETHER_DIR, "module/hadron/src/lib/**.cpp"),
	}
