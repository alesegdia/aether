dofile("aether-allegro-files.lua")
dofile("aether-gl-files.lua")
dofile("aether-raylib-files.lua")
dofile("aether-sdl-files.lua")


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
	path.join(AETHER_EXTERNALS_DIR, "tweeny/include/*"),
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
	path.join(AETHER_EXTERNALS_DIR, "enet/include"),
	path.join(AETHER_PLUGINS_DIR, "astarcpp/src"),
	path.join(AETHER_EXTERNALS_DIR, "tweeny/include"),
}

AETHER_DUMMY_AUDIO_SOURCES = {
	path.join(AETHER_DIR, "src/aether/audio/dummy/*.h"),
	path.join(AETHER_DIR, "src/aether/audio/dummy/*.cpp"),
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
	"enet"
}
