dofile("../util/common.lua")

externalCommonLibSetup("imgui", true)
    language "C++"
    configuration {}

    configAllegro(true)
    configSDL()

    configuration {}

    includedirs {
		path.join(AETHER_EXTERNALS_DIR, "imgui"),
		path.join(AETHER_EXTERNALS_DIR, "imgui/backends/"),			
		path.join(AETHER_EXTERNALS_DIR, "L2DFileDialog/"),			
    }

    files {
		path.join(AETHER_EXTERNALS_DIR, "imgui/*.h"),
		path.join(AETHER_EXTERNALS_DIR, "imgui/*.cpp"),
    }

	configuration { "backend-sdl" }
		files {
			path.join(AETHER_EXTERNALS_DIR, "imgui/backends/imgui_impl_sdl.h"),
			path.join(AETHER_EXTERNALS_DIR, "imgui/backends/imgui_impl_sdl.cpp"),
		}

	configuration { "backend-allegro" }
		files {
			path.join(AETHER_EXTERNALS_DIR, "imgui/backends/imgui_impl_allegro5.h"),
			path.join(AETHER_EXTERNALS_DIR, "imgui/backends/imgui_impl_allegro5.cpp"),
		}

