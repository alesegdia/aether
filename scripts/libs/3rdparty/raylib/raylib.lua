dofile("raylib-files.lua")
dofile("../util/cmake-configure.lua")

externalCommonLibSetup("raylib")

	configuration {}
	
	defines {
		"SUPPORT_CUSTOM_FRAME_CONTROL",
		"_GLFW_WIN32",
		"PLATFORM_DESKTOP",
	}
	
	includedirs {
		RAYLIB_INCLUDE_DIRS
	}

	files {
		RAYLIB_SRC_FILES,
	}

