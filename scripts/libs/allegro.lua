dofile("allegro-files.lua")
dofile("../util/cmake-configure.lua")

if (_ACTION == "vs2019" or _ACTION == "vs2022") and _OPTIONS["backend"] == "backend-allegro" then
    cmakeConfigureFileImmediate(path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alplatf.h.cmake"),
        {
            "ALLEGRO_MSVC",
            "ALLEGRO_LITTLE_ENDIAN",
            "ALLEGRO_HAVE_STDBOOL_H",
            "ALLEGRO_HAVE_SYS_TYPES_H",
            "ALLEGRO_HAVE_INTTYPES_H",
            "ALLEGRO_HAVE_STDINT_H",
            "ALLEGRO_HAVE_SYS_STAT_H"
        })
    cmakeConfigureFileImmediate(path.join(AETHER_DIR, "module/allegro/addons/ttf/allegro5/internal/aintern_ttf_cfg.h.cmake"),
        {
            "ALLEGRO_CFG_TTF_FREETYPE",
        })

    cmakeConfigureFileImmediate(path.join(AETHER_DIR, "module/allegro/addons/image/allegro5/internal/aintern_image_cfg.h.cmake"),
        {
            "ALLEGRO_CFG_IIO_HAVE_PNG",
            "ALLEGRO_CFG_IIO_SUPPORT_PNG",
        })

end

commonLibSetup("allegro", true)
    language "C++"
    configuration {}

    includedirs {
        path.join(AETHER_DIR, "module/allegro/include"),
        ALLEGRO_ADDON_TTF_INCLUDE,
        ALLEGRO_ADDON_FONT_INCLUDE,
        ALLEGRO_ADDON_IMAGE_INCLUDE,
        ALLEGRO_ADDON_COLOR_INCLUDE,
        path.join(AETHER_DIR, "module/freetype/include"),
        path.join(AETHER_DIR, "module/libpng/"),
        --path.join(AETHER_DIR, "module/sdl/include"),
        path.join(AETHER_DIR, "module/zlib/"),
        path.join(AETHER_DIR, "module/dxsdk/Include")
    }

    files {
        ALLEGRO_SRC_FILES,
        ALLEGRO_INCLUDE_ALLEGRO_FILES,
        ALLEGRO_INCLUDE_ALLEGRO_PLATFORM_FILES_GENERATED,
        ALLEGRO_ADDON_FONT_FILES,
        ALLEGRO_ADDON_TTF_FILES,
        ALLEGRO_ADDON_PRIMITIVE_FILES,
        ALLEGRO_ADDON_IMAGE_FILES,
        ALLEGRO_ADDON_COLOR_FILES,
        ALLEGRO_ADDON_PRIMITIVE_WINDOWS_FILES,
        ALLEGRO_SRC_D3D_FILES,
        ALLEGRO_SRC_OPENGL_FILES,
        ALLEGRO_SRC_WGL_FILES,
        --ALLEGRO_SRC_SDL_FILES,
        ALLEGRO_INCLUDE_ALLEGRO_OPENGL_GLEXT_FILES,
    }

    defines {
        "ALLEGRO_SRC",
        "ALLEGRO_FONT_SRC",
        "ALLEGRO_LIB_BUILD",
        --"ALLEGRO_USE_SDL",
        "UNICODE",
        "_UNICODE",
        "ALLEGRO_STATICLINK",
        "ALLEGRO_TTF_SRC",
        "ALLEGRO_CFG_D3D",
        "ALLEGRO_CFG_OPENGL",
        "ALLEGRO_CFG_OPENGL_PROGRAMMABLE_PIPELINE",
        "ALLEGRO_CFG_SHADER_GLSL",
        "ALLEGRO_CFG_SHADER_HLSL",
        "ALLEGRO_CFG_D3DX9",
        "ALLEGRO_CFG_RELEASE_LOGGING",
    }

    configuration { "vs20*" }
        files {
            ALLEGRO_SRC_WIN_FILES,
            ALLEGRO_INCLUDE_ALLEGRO_PLATFORM_FILES_GENERATED,
            ALLEGRO_ADDON_PRIMITIVE_WINDOWS_FILES,
        }
        defines {
            "HAVE_LIBC",
        }


