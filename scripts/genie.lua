AETHER_DIR = path.getabsolute("../")

dofile("aether-project.lua")

solution "aether"

	location "../build"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }

	dofile("external/sdl.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}
	dofile("external/sdl_ttf.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}
	dofile("external/sdl_image.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}
	dofile("external/tinyxml2.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}
	dofile("external/tmxparser.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}
	dofile("external/tmxparser.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}
	dofile("external/json11.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}
	dofile("external/hadron.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}
	dofile("external/secs.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}
	dofile("external/rztl.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}
	dofile("aether.lua")
		flags {
			"Symbols",
			"StaticRuntime"
		}

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
