commonLibSetup("gtest")
	language "C++"
	configuration {}
	
	includedirs {
		path.join(AETHER_DIR, "module/googletest/googletest/include"),
		path.join(AETHER_DIR, "module/googletest/googlemock/include"),
	}

	files {
		path.join(AETHER_DIR, "module/googletest/googletest/src/**.cc"),
		path.join(AETHER_DIR, "module/googletest/googletest/src/**.h"),
		path.join(AETHER_DIR, "module/googletest/googlemock/src/**.cc"),
		path.join(AETHER_DIR, "module/googletest/googlemock/src/**.h"),
	}
