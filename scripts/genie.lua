AETHER_DIR = path.getabsolute("../")

dofile("common-lib-setup.lua")
dofile("aether-project.lua")
dofile("sdl-backend.lua")

solution "aether"

	location "../build"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }

	dofile("aether-build.lua")

	aetherProject("basic")
		debugdir (AETHER_DIR)
		files {
			path.join(AETHER_DIR, "examples/basic/main.cpp")
		}

	aetherProject("input")
		debugdir (AETHER_DIR)
		files {
			path.join(AETHER_DIR, "examples/input/main.cpp")
		}
		flags {
			"Symbols",
			"StaticRuntime"
		}

	aetherProject("texture")
		debugdir (AETHER_DIR)
		files {
			path.join(AETHER_DIR, "examples/basic/texture.cpp")
		}
