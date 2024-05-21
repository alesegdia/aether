dofile("../aether-config.lua")
dofile(path.join(AETHER_DIR, "scripts/util/util.lua"))

aetherConfig()

solution "<PROJECT-NAME>"
	startproject("<PROJECT-NAME>-game")
	location "../build/"
	configurations { "debug", "release" }
	platforms { "x32", "x64" }
	language "C++"
	
	aetherBuild()

	aetherGameLib("<PROJECT-NAME>-game")
		debugdir ("..")
		targetdir ("../build")
		files {
			"../src/**.cpp",
			"../src/**.h"
		}
		includedirs {
			"../src"
		}

