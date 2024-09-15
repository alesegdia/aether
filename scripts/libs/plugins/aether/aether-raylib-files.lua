AETHER_RAYLIB_SOURCES = {
	path.join(AETHER_DIR, "src/aether/audio/raylib/*.h"),
	path.join(AETHER_DIR, "src/aether/audio/raylib/*.cpp"),
	path.join(AETHER_DIR, "src/aether/render/raylib/*.h"),
	path.join(AETHER_DIR, "src/aether/render/raylib/*.cpp"),
	path.join(AETHER_DIR, "src/aether/core/raylib/*.h"),
	path.join(AETHER_DIR, "src/aether/core/raylib/*.cpp"),
}

AETHER_RAYLIB_INCLUDE_DIRS = {
    path.join(AETHER_EXTERNALS_DIR, "raylib/src"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/deps/mingw"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/include"),
}
