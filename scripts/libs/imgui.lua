dofile("../util/common.lua")

commonLibSetup("imgui")
    language "C++"
    configuration {}

    configAllegro(true)
    configSDL()

    configuration {}

    includedirs {
		path.join(AETHER_DIR, "module/imgui"),
		path.join(AETHER_DIR, "module/imgui/backends/"),			
		path.join(AETHER_DIR, "module/L2DFileDialog/"),			
    }

    files {
		path.join(AETHER_DIR, "module/imgui/*.h"),
		path.join(AETHER_DIR, "module/imgui/*.cpp"),
    }

	configuration { "backend-sdl" }
		files {
			path.join(AETHER_DIR, "module/imgui/backends/imgui_impl_sdl.h"),
			path.join(AETHER_DIR, "module/imgui/backends/imgui_impl_sdl.cpp"),
		}

	configuration { "backend-allegro" }
		files {
			path.join(AETHER_DIR, "module/imgui/backends/imgui_impl_allegro5.h"),
			path.join(AETHER_DIR, "module/imgui/backends/imgui_impl_allegro5.cpp"),
		}

