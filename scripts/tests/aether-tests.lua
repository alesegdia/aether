aetherProject("aether-tests")
	includedirs {
		path.join(AETHER_DIR, "module/googletest/googletest/include"),
		path.join(AETHER_DIR, "module/googletest/googlemock/include"),
	}
	debugdir ("..")
	targetdir ("../build")
	links { "gtest" }
	files {
    		path.join(AETHER_DIR, "module/secs/src/gtests/**.cpp"),
	}
