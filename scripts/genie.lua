AETHER_DIR = path.getabsolute("../")

dofile("aether-project.lua")

solution "aether"

	location "../build"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }

	dofile("aether-build.lua")

	newAetherExample("basic")
		debugdir (AETHER_DIR)
		files {
			path.join(AETHER_DIR, "examples/basic/main.cpp")
		}

	newAetherExample("input")
		debugdir (AETHER_DIR)
		files {
			path.join(AETHER_DIR, "examples/input/main.cpp")
		}
		flags {
			"Symbols",
			"StaticRuntime"
		}

	newAetherExample("texture")
		debugdir (AETHER_DIR)
		files {
			path.join(AETHER_DIR, "examples/basic/texture.cpp")
		}
