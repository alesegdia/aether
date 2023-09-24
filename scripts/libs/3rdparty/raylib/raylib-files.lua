RAYLIB_SRC_FILES = {
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/config.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/raudio.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/raylib.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/raymath.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/rcamera.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/rcore.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/rgestures.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/rglfw.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/rlgl.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/rmodels.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/rshapes.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/rtext.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/rtextures.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/utils.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/utils.c"),
    --[[
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/*.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/win32*.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/win32*.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/wgl_context.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/include/GLFW/glfw3.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/include/GLFW/glfw3native.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/internal.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/platform.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/mappings.h"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/context.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/init.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/input.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/monitor.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/platform.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/vulkan.c"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/src/window.c"),
]]--
}


RAYLIB_INCLUDE_DIRS = {
    path.join(AETHER_EXTERNALS_DIR, "raylib/src"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/deps/mingw"),
    path.join(AETHER_EXTERNALS_DIR, "raylib/src/external/glfw/include"),
}