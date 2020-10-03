AETHER_DIR = path.getabsolute("../")

function newAetherExample(exampleName, exampleSources)
	project ("aether-" .. exampleName)
	kind "ConsoleApp"
	language "C++"
	links {
		"sdl",
		"sdl-ttf",
		"sdl-image",
		"tinyxml2",
		"tmxparser",
		"aether"
	}
	
	dofile(path.join(AETHER_DIR, "scripts/common-flags.lua"))

	configuration { "vs20*" }
		links {
			"DelayImp",
			"gdi32",
			"psapi",
			"Winmm",
			"imm32",
			"version",
			"Setupapi",
			"MSVCRTD",
		}
	configuration {}
		includedirs {
			path.join(AETHER_DIR, "src"),
			path.join(AETHER_DIR, "module/sdl/include"),
			path.join(AETHER_DIR, "module/sdl/src/hidapi/hidapi"),
			path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/include"),
			path.join(AETHER_DIR, "module/sdl-ttf"),
			path.join(AETHER_DIR, "module/sdl-image"),
			path.join(AETHER_DIR, "module/tinyxml2"),
			path.join(AETHER_DIR, "module/tmxparser/include"),
			path.join(AETHER_DIR, "module/rztl/include"),
			path.join(AETHER_DIR, "module/secs/src/lib"),
			path.join(AETHER_DIR, "module/hadron/src/lib"),
			path.join(AETHER_DIR, "module/json11"),
		}
	defines {
		"AETHER_USE_SDL"
	}
		flags {
			"Symbols",
			"StaticRuntime"
		}

end

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
