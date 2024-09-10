dofile("aether-sdl-files.lua")

AETHER_GL_CORE_SOURCES = {
	AETHER_SDL_CORE_SOURCES,
	path.join(AETHER_PLUGINS_DIR, "nether/src/nether/**.*"),
	path.join(AETHER_EXTERNALS_DIR, "glad/include/glad/gl.h"),
	path.join(AETHER)
}

AETHER_GL_GRAPHICS_SOURCES = {
	path.join(AETHER_DIR, "src/aether/graphics/gl/*.h"),
	path.join(AETHER_DIR, "src/aether/graphics/gl/*.cpp"),
}

AETHER_GL_AUDIO_SOURCES = {
	AETHER_SDL_AUDIO_SOURCES
}

AETHER_GL_INCLUDE_DIRS = {
	AETHER_SDL_INCLUDE_DIRS,
	path.join(AETHER_PLUGINS_DIR, "nether/src/nether/"),
	path.join(AETHER_EXTERNALS_DIR, "glad/include"),
}

AETHER_GL_WIN_LIBS = {
	AETHER_SDL_WIN_LIBS,
	"opengl32"
}

AETHER_GL_COMMON_LIBS = {
	AETHER_SDL_COMMON_LIBS,

}
