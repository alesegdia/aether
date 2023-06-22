AETHER_COMMON_SOURCES = {
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
	path.join(AETHER_DIR, "src/aether/lua/*.h"),
	path.join(AETHER_DIR, "src/aether/lua/*.cpp"),
	path.join(AETHER_DIR, "src/aether/gui/*.h"),
	path.join(AETHER_DIR, "src/aether/gui/*.cpp"),
	path.join(AETHER_EXTERNALS_DIR, "inipp/inipp/*.h"),
	path.join(AETHER_EXTERNALS_DIR, "astarcpp/src/astar.h"),
}

AETHER_API_SOURCES = {
	path.join(AETHER_DIR ,"src/aether/api/*.h"),
	path.join(AETHER_DIR ,"src/aether/api/*.cpp")
}

AETHER_API_INCLUDE_DIRS = {
	path.join(AETHER_DIR ,"src/aether/api/")
}

AETHER_COMMON_INCLUDE_DIRS = {
	path.join(AETHER_DIR, "src"),
	path.join(AETHER_EXTERNALS_DIR, "tinyxml2"),
	path.join(AETHER_EXTERNALS_DIR, "tmxparser/include"),
	path.join(AETHER_PLUGINS_DIR, "rztl/include"),
	path.join(AETHER_PLUGINS_DIR, "secs/src/lib"),
	path.join(AETHER_PLUGINS_DIR, "hadron/src/lib"),
	path.join(AETHER_EXTERNALS_DIR, "json11"),
	path.join(AETHER_EXTERNALS_DIR, "imgui"),
	path.join(AETHER_EXTERNALS_DIR, "imgui/backends"),
	path.join(AETHER_EXTERNALS_DIR, "lua"),
	path.join(AETHER_EXTERNALS_DIR, "inipp"),
	path.join(AETHER_PLUGINS_DIR, "astarcpp/src"),
}

AETHER_ALLEGRO_CORE_SOURCES = {
	path.join(AETHER_DIR, "src/aether/core/allegro/*.h"),
	path.join(AETHER_DIR, "src/aether/core/allegro/*.cpp"),
}

AETHER_ALLEGRO_GRAPHICS_SOURCES = {
	path.join(AETHER_DIR, "src/aether/graphics/allegro/*.h"),
	path.join(AETHER_DIR, "src/aether/graphics/allegro/*.cpp"),
}

AETHER_ALLEGRO_AUDIO_SOURCES = {
	path.join(AETHER_DIR, "src/aether/audio/allegro/*.h"),
	path.join(AETHER_DIR, "src/aether/audio/allegro/*.cpp"),
}

AETHER_ALLEGRO_INCLUDE_DIRS = {
	path.join(AETHER_EXTERNALS_DIR, "allegro/include"),
	path.join(AETHER_EXTERNALS_DIR, "allegro/addons/font/"),
	path.join(AETHER_EXTERNALS_DIR, "allegro/addons/image"),
	path.join(AETHER_EXTERNALS_DIR, "allegro/addons/primitives"),
	path.join(AETHER_EXTERNALS_DIR, "allegro/addons/ttf"),
}

AETHER_DUMMY_AUDIO_SOURCES = {
	path.join(AETHER_DIR, "src/aether/audio/dummy/*.h"),
	path.join(AETHER_DIR, "src/aether/audio/dummy/*.cpp"),
}

AETHER_SDL_CORE_SOURCES = {
	path.join(AETHER_DIR, "src/aether/core/sdl/*.h"),
	path.join(AETHER_DIR, "src/aether/core/sdl/*.cpp"),
}

AETHER_SDL_GRAPHICS_SOURCES = {
	path.join(AETHER_DIR, "src/aether/graphics/sdl/*.h"),
	path.join(AETHER_DIR, "src/aether/graphics/sdl/*.cpp"),
}

AETHER_SDL_AUDIO_SOURCES = {
	path.join(AETHER_DIR, "src/aether/audio/sdl/*.h"),
	path.join(AETHER_DIR, "src/aether/audio/sdl/*.cpp"),
}

AETHER_SDL_INCLUDE_DIRS = {
	path.join(AETHER_EXTERNALS_DIR, "sdl/include"),
	path.join(AETHER_EXTERNALS_DIR, "sdl/src/hidapi/hidapi"),
	path.join(AETHER_EXTERNALS_DIR, "sdl-ttf/external/freetype-2.10.1/include"),
	path.join(AETHER_EXTERNALS_DIR, "sdl-ttf"),
	path.join(AETHER_EXTERNALS_DIR, "sdl-image"),
}

AETHER_RAYLIB_SOURCES = {
	path.join(AETHER_DIR, "src/aether/audio/raylib/*.h"),
	path.join(AETHER_DIR, "src/aether/audio/raylib/*.cpp"),
	path.join(AETHER_DIR, "src/aether/graphics/raylib/*.h"),
	path.join(AETHER_DIR, "src/aether/graphics/raylib/*.cpp"),
	path.join(AETHER_DIR, "src/aether/core/raylib/*.h"),
	path.join(AETHER_DIR, "src/aether/core/raylib/*.cpp"),
}

AETHER_RAYLIB_INCLUDE_DIRS = {
    path.join(AETHER_EXTERNALS_DIR, "raylib/src"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/deps/mingw"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/include"),
}

AETHER_COMMON_LIBS = {
	"tinyxml2",
	"tmxparser",
	"secs",
	"hadron",
	"aether",
	"json11",
	"imgui",
	"lua",
}

AETHER_SDL_WIN_LIBS = {
	"DelayImp",
	"gdi32",
	"psapi",
	"Winmm",
	"imm32",
	"version",
	"Setupapi",
}

AETHER_SDL_COMMON_LIBS = {
	"libpng",
	"zlib",
    "freetype",
	"sdl",
	"sdl-ttf",
	"sdl-image",
}

AETHER_ALLEGRO_WIN_LIBS = {
    "user32",
    "gdi32",
    "comdlg32",
    "ole32",
    "winmm",
    "kernel32",
    "psapi",
    "shlwapi",
}

AETHER_ALLEGRO_COMMON_LIBS = {
	"allegro",
    "libpng",
    "zlib",
    "freetype",
}