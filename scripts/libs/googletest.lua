externalCommonLibSetup("gtest")
	language "C++"
	configuration {}
	
	includedirs {
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/include"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/include"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/"),
	}

	files {
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest-assertion-result.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest-death-test.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest-filepath.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest-internal-inl.h"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest-matchers.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest-port.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest-printers.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest-test-part.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest-typed-test.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest.cc"),
		--path.join(AETHER_EXTERNALS_DIR, "googletest/googletest/src/gtest_main.cc"),

		--path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/gmock-all.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/src/gmock-cardinalities.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/src/gmock-internal-utils.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/src/gmock-matchers.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/src/gmock-spec-builders.cc"),
		path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/src/gmock.cc"),
		--path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/gmock_main.cc"),

		--path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/src/**.cc"),
		--path.join(AETHER_EXTERNALS_DIR, "googletest/googlemock/src/**.h"),
	}
