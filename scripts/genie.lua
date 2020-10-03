AETHER_DIR = path.getabsolute("../")


solution "aether"

	location "../build"
	configurations { "Debug", "Dev", "Release" }
	platforms { "native", "x32", "x64" }

	dofile("thirdparty/sdl.lua")
	dofile("thirdparty/sdl_ttf.lua")
	dofile("thirdparty/sdl_image.lua")

	project "aether-lib"
		location "../build"
		kind "StaticLib"
		language "C++"
		files {
			path.join(AETHER_DIR, "src/aether/meh.h"),
			path.join(AETHER_DIR, "src/aether/meh.cpp")
		}
		flags { "ExtraWarnings", "FatalWarnings" }
		links("sdl")
		includedirs {
			path.join(AETHER_DIR, "module/sdl/include"),
			path.join(AETHER_DIR, "module/sdl/src/hidapi/hidapi"),
		}


	project "example-001"
		location "../build"
		kind "ConsoleApp"
		language "C++"
		links {
			"sdl",
			"sdl-ttf",
			"sdl-image",
		}
		debugdir("..")
		files {
			path.join(AETHER_DIR, "src/examples/helloworld.cpp")
		}
		includedirs {
			path.join(AETHER_DIR, "module/sdl/include"),
			path.join(AETHER_DIR, "module/sdl/src/hidapi/hidapi"),
			path.join(AETHER_DIR, "module/sdl-ttf/external/freetype-2.10.1/include"),
		}
		configuration{"vs20*"}
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



