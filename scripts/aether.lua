project "aether"
	location "../build"
	kind "StaticLib"
	language "C++"
	targetdir (path.join(AETHER_DIR, "../../bin/lib"))

	files {
		path.join(AETHER_DIR, "src/aether/aether.h"),
		path.join(AETHER_DIR, "src/aether/audio/*.h"),
		path.join(AETHER_DIR, "src/aether/audio/*.cpp"),
		path.join(AETHER_DIR, "src/aether/core/*.h"),
		path.join(AETHER_DIR, "src/aether/core/*.cpp"),
		path.join(AETHER_DIR, "src/aether/debug/*.h"),
		path.join(AETHER_DIR, "src/aether/debug/*.cpp"),
		path.join(AETHER_DIR, "src/aether/graphics/*.h"),
		path.join(AETHER_DIR, "src/aether/graphics/*.cpp"),
		path.join(AETHER_DIR, "src/aether/map/*.h"),
		path.join(AETHER_DIR, "src/aether/map/*.cpp"),
		path.join(AETHER_DIR, "src/aether/math/*.h"),
		path.join(AETHER_DIR, "src/aether/math/*.cpp"),
		path.join(AETHER_DIR, "src/aether/resources/*.h"),
		path.join(AETHER_DIR, "src/aether/resources/*.cpp"),
		path.join(AETHER_DIR, "src/aether/scene/*.h"),
		path.join(AETHER_DIR, "src/aether/scene/*.cpp"),
	}
	
	flags { "ExtraWarnings", "FatalWarnings" }
	
	configuration { "vs20*" }
		defines {
			"AETHER_USE_SDL"
		}

		files {
			path.join(AETHER_DIR, "src/aether/audio/sdl/*.h"),
			path.join(AETHER_DIR, "src/aether/audio/sdl/*.cpp"),
			path.join(AETHER_DIR, "src/aether/core/sdl/*.h"),
			path.join(AETHER_DIR, "src/aether/core/sdl/*.cpp"),
			path.join(AETHER_DIR, "src/aether/graphics/sdl/*.h"),
			path.join(AETHER_DIR, "src/aether/graphics/sdl/*.cpp"),
		}

		includedirs {
			path.join(AETHER_DIR, "module/sdl/include"),
			path.join(AETHER_DIR, "module/sdl/src/hidapi/hidapi"),
		}
