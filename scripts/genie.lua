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
		"rztl",
		"aether"
	}
	configuration { "vs20*" }
		links {
			"DelayImp",
			"gdi32",
			"psapi",
			"Winmm",
			"imm32",
			"version",
			"Setupapi",
			"MSVCRT",
		}
	configuration {}
		includedirs {
			path.join(AETHER_DIR, "src"),
			path.join(AETHER_DIR, "module/sdl/include"),
			path.join(AETHER_DIR, "module/sdl/src/hidapi/hidapi"),
			path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/include"),
			path.join(AETHER_DIR, "module/tinyxml2"),
			path.join(AETHER_DIR, "module/tmxparser/include"),
			path.join(AETHER_DIR, "module/rztl/include"),
			path.join(AETHER_DIR, "module/secs/src/lib"),
			path.join(AETHER_DIR, "module/hadron/src/lib"),
			path.join(AETHER_DIR, "module/json11"),
		}
end

solution "aether"

	location "../build"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }

	dofile("external/sdl.lua")
	dofile("external/sdl_ttf.lua")
	dofile("external/sdl_image.lua")
	dofile("external/tinyxml2.lua")
	dofile("external/tmxparser.lua")
	dofile("external/tmxparser.lua")
	dofile("external/json11.lua")
	dofile("external/hadron.lua")
	dofile("external/secs.lua")
	dofile("external/rztl.lua")
	dofile("aether.lua")

	newAetherExample("example-001")
		files {
			path.join(AETHER_DIR, "src/examples/helloworld.cpp")
		}
