
file(GLOB AETHER_COMMON_SOURCES
	${SDL_SOURCE_DIR}/src/aether/aether.h
	${SDL_SOURCE_DIR}/src/aether/platform.h
	${SDL_SOURCE_DIR}/src/aether/audio/*.h
	${SDL_SOURCE_DIR}/src/aether/audio/*.cpp
	${SDL_SOURCE_DIR}/src/aether/core/*.h
	${SDL_SOURCE_DIR}/src/aether/core/*.cpp
	${SDL_SOURCE_DIR}/src/aether/debug/*.h
	${SDL_SOURCE_DIR}/src/aether/debug/*.cpp
	${SDL_SOURCE_DIR}/src/aether/graphics/*.h
	${SDL_SOURCE_DIR}/src/aether/graphics/*.cpp
	${SDL_SOURCE_DIR}/src/aether/map/*.h
	${SDL_SOURCE_DIR}/src/aether/map/*.cpp
	${SDL_SOURCE_DIR}/src/aether/math/*.h
	${SDL_SOURCE_DIR}/src/aether/math/*.cpp
	${SDL_SOURCE_DIR}/src/aether/resources/*.h
	${SDL_SOURCE_DIR}/src/aether/resources/*.cpp
	${SDL_SOURCE_DIR}/src/aether/scene/*.h
	${SDL_SOURCE_DIR}/src/aether/scene/*.cpp
)

file(GLOB AETHER_COMMON_INCDIRS
	${SDL_SOURCE_DIR}/src
	${SDL_SOURCE_DIR}/module/tinyxml2
	${SDL_SOURCE_DIR}/module/tmxparser/include
	${SDL_SOURCE_DIR}/module/rztl/include
	${SDL_SOURCE_DIR}/module/secs/src/lib
	${SDL_SOURCE_DIR}/module/hadron/src/lib
	${SDL_SOURCE_DIR}/module/json11
)

file(GLOB AETHER_ALLEGRO_CORE_SOURCES
	${SDL_SOURCE_DIR}/src/aether/core/allegro/*.h
	${SDL_SOURCE_DIR}/src/aether/core/allegro/*.cpp
)

file(GLOB AETHER_ALLEGRO_GRAPHICS_SOURCES
	${SDL_SOURCE_DIR}/src/aether/graphics/allegro/*.h
	${SDL_SOURCE_DIR}/src/aether/graphics/allegro/*.cpp
)

file(GLOB AETHER_ALLEGRO_AUDIO_SOURCES
	${SDL_SOURCE_DIR}/src/aether/audio/allegro/*.h
	${SDL_SOURCE_DIR}/src/aether/audio/allegro/*.cpp
)

file(GLOB AETHER_ALLEGRO_INCDIRS
	${SDL_SOURCE_DIR}/module/allegro/include
	${SDL_SOURCE_DIR}/module/allegro/addons/font/
	${SDL_SOURCE_DIR}/module/allegro/addons/image
	${SDL_SOURCE_DIR}/module/allegro/addons/primitives
	${SDL_SOURCE_DIR}/module/allegro/addons/ttf
)

file(GLOB AETHER_DUMMY_AUDIO_SOURCES
	${SDL_SOURCE_DIR}/src/aether/audio/dummy/*.h
	${SDL_SOURCE_DIR}/src/aether/audio/dummy/*.cpp
)

file(GLOB AETHER_SDL_CORE_SOURCES
	${SDL_SOURCE_DIR}/src/aether/core/sdl/*.h
	${SDL_SOURCE_DIR}/src/aether/core/sdl/*.cpp
)

file(GLOB AETHER_SDL_GRAPHICS_SOURCES
	${SDL_SOURCE_DIR}/src/aether/graphics/sdl/*.h
	${SDL_SOURCE_DIR}/src/aether/graphics/sdl/*.cpp
)

file(GLOB AETHER_SDL_AUDIO_SOURCES
	${SDL_SOURCE_DIR}/src/aether/audio/sdl/*.h
	${SDL_SOURCE_DIR}/src/aether/audio/sdl/*.cpp
)

file(GLOB AETHER_SDL_INCDIRS
	${SDL_SOURCE_DIR}/module/sdl/include
	${SDL_SOURCE_DIR}/module/sdl/src/hidapi/hidapi
	${SDL_SOURCE_DIR}/module/sdl-ttf/external/freetype-2.10.1/include
	${SDL_SOURCE_DIR}/module/sdl-ttf
	${SDL_SOURCE_DIR}/module/sdl-image
)

set(AETHER_COMMON_LIBS "tinyxml2 tmxparser secs hadron aether freetype json11")
set(AETHER_SDL_WIN_LIBS "DelayImp gdi32 psapi Winmm imm32 version Setupapi")
set(AETHER_SDL_COMMON_LIBS "libpng zlib freetype sdl sdl-ttf sdl-image")

set(GLOB AETHER_ALLEGRO_WIN_LIBS "user32 gdi32 comdlg32 ole32 winmm kernel32 psapi shlwapi")

set(GLOB AETHER_ALLEGRO_COMMON_LIBS "allegro libpng zlib freetype")

