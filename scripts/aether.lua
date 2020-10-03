project "aether"
	location "../build"
	kind "StaticLib"
	language "C++"
	targetdir (path.join(AETHER_DIR, "/bin/lib"))

	files {
		path.join(AETHER_DIR, "src/aether/aether.h"),
		path.join(AETHER_DIR, "src/aether/platform.h"),
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
	
	dofile(path.join(AETHER_DIR, "scripts/common-flags.lua"))

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
