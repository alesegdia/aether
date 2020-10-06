dofile("allegro-files.lua")
dofile("../util/cmake-configure.lua")

if _ACTION == "vs2019" and _OPTIONS["backend"] == "backend-allegro" then
    cmakeConfigureFileImmediate(path.join(AETHER_DIR, "module/allegro/include/allegro5/platform/alplatf.h.cmake"),
        {
            "ALLEGRO_MSVC",
            "ALLEGRO_BIG_ENDIAN",
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

commonLibSetup("allegro")
    language "C++"
    configuration {}

    includedirs {
        path.join(AETHER_DIR, "module/allegro/include"),
        ALLEGRO_ADDON_TTF_INCLUDE,
        ALLEGRO_ADDON_FONT_INCLUDE,
        ALLEGRO_ADDON_IMAGE_INCLUDE,
        path.join(AETHER_DIR, "module/freetype/include"),
        path.join(AETHER_DIR, "module/libpng/"),
        path.join(AETHER_DIR, "module/zlib/"),
    }

    files {
        ALLEGRO_SRC_FILES,
        ALLEGRO_INCLUDE_ALLEGRO_FILES,
        ALLEGRO_INCLUDE_ALLEGRO_PLATFORM_FILES_GENERATED,
        ALLEGRO_ADDON_FONT_FILES,
        ALLEGRO_ADDON_TTF_FILES,
        ALLEGRO_ADDON_PRIMITIVE_FILES,
        ALLEGRO_ADDON_IMAGE_FILES,
        ALLEGRO_SRC_D3D_FILES,
        ALLEGRO_ADDON_PRIMITIVE_WINDOWS_FILES,
    }

    defines {
        "ALLEGRO_SRC",
        "ALLEGRO_FONT_SRC",
        "ALLEGRO_LIB_BUILD",
        "ALLEGRO_USE_SDL",
        "UNICODE",
        "_UNICODE",
        "ALLEGRO_STATICLINK",
        "ALLEGRO_TTF_SRC",
        "ALLEGRO_CFG_D3D",
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


