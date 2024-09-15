
AETHER_SDL_CORE_SOURCES = {
	path.join(AETHER_DIR, "src/aether/core/sdl/*.h"),
	path.join(AETHER_DIR, "src/aether/core/sdl/*.cpp"),
}

AETHER_SDL_RENDER_SOURCES = {
	path.join(AETHER_DIR, "src/aether/render/sdl/*.h"),
	path.join(AETHER_DIR, "src/aether/render/sdl/*.cpp"),
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
