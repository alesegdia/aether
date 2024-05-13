
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
	path.join(AETHER_EXTERNALS_DIR, "allegro/addons/audio/"),
	path.join(AETHER_EXTERNALS_DIR, "allegro/addons/acodec/"),
	path.join(AETHER_EXTERNALS_DIR, "allegro/addons/image"),
	path.join(AETHER_EXTERNALS_DIR, "allegro/addons/primitives"),
	path.join(AETHER_EXTERNALS_DIR, "allegro/addons/ttf"),
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