dofile("../aether.config.lua")
AETHER_DIR = path.getabsolute("../plugin/aether")

dofile(path.join(AETHER_DIR, "scripts/util/util.lua"))

aetherConfig()

solution "lichwarrior"
	startproject("lichwarrior-game")
	location "../build/"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }
	language "C++"
	
	aetherBuild()

	aetherGameLib("lichwarrior-game")
		debugdir ("..")
		targetdir ("../build")
		files {
			"../src/**.cpp",
			"../src/**.h"
		}
		includedirs {
			"../src"
		}

