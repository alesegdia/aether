function aetherProject(exampleName)
	project ("aether-" .. exampleName)
	kind "ConsoleApp"
	language "C++"
	links {
		"sdl",
		"sdl-ttf",
		"sdl-image",
		"tinyxml2",
		"tmxparser",
		"aether",
		"secs",
		"hadron",
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
