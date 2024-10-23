AETHER_GL_CORE_SOURCES = {

	path.join(AETHER_DIR, "src/aether/core/sdl/sdl_input.cpp"),
	path.join(AETHER_DIR, "src/aether/core/sdl/sdl_keycode.h"),
	path.join(AETHER_DIR, "src/aether/core/sdl/sdl_time.cpp"),
	path.join(AETHER_DIR, "src/aether/core/gl/**.h"),
	path.join(AETHER_DIR, "src/aether/core/gl/**.cpp"),

	path.join(AETHER_PLUGINS_DIR, "nether/src/nether/**.*"),
	path.join(AETHER_EXTERNALS_DIR, "glad/include/glad/gl.h"),
	path.join(AETHER)
}

AETHER_GL_RENDER_SOURCES = {
	path.join(AETHER_DIR, "src/aether/render/gl/*.h"),
	path.join(AETHER_DIR, "src/aether/render/gl/*.cpp"),
	path.join(AETHER_DIR, "src/aether/platform/gl/*.h"),
	path.join(AETHER_DIR, "src/aether/platform/gl/*.cpp"),
}

AETHER_GL_AUDIO_SOURCES = {
	path.join(AETHER_DIR, "src/aether/audio/sdl/*.h"),
	path.join(AETHER_DIR, "src/aether/audio/sdl/*.cpp"),
}

AETHER_GL_INCLUDE_DIRS = {
	path.join(AETHER_EXTERNALS_DIR, "sdl/include"),
	path.join(AETHER_EXTERNALS_DIR, "sdl/src/hidapi/hidapi"),
	path.join(AETHER_EXTERNALS_DIR, "sdl-ttf/external/freetype-2.10.1/include"),
	path.join(AETHER_EXTERNALS_DIR, "sdl-ttf"),
	path.join(AETHER_EXTERNALS_DIR, "sdl-image"),

	path.join(AETHER_PLUGINS_DIR, "nether/src/"),
	path.join(AETHER_PLUGINS_DIR, "nether/3rdparty/stb/"),
	path.join(AETHER_PLUGINS_DIR, "nether/3rdparty/glm/"),
	path.join(AETHER_EXTERNALS_DIR, "glad/include"),
}

AETHER_GL_WIN_LIBS = {
	"DelayImp",
	"gdi32",
	"psapi",
	"Winmm",
	"imm32",
	"version",
	"Setupapi",
	"opengl32"
}

AETHER_GL_COMMON_LIBS = {
	"libpng",
	"zlib",
    "freetype",
	"sdl",
}




