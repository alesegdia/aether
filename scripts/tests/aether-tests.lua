aetherProject("aether-tests")
	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/include"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/include"),
	}
	debugdir ("..")
	targetdir ("../build")
	links { "gtest" }
	files {
    		path.join(AETHER_PLUGINS_DIR, "secs/src/gtests/**.cpp"),
	}
