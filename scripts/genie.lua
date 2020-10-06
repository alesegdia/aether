AETHER_DIR = path.getabsolute("../")

dofile(path.join(AETHER_DIR, "scripts/util/util.lua"))

aetherConfig()

solution "aether"

	location "../build"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }

	aetherBuild()

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
