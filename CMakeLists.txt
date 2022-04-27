cmake_minimum_required(VERSION 3.0.0)

project(aether)

set(CMAKE_MODULE_PATH "${AETHER_SOURCE_DIR}/cmake")

include(${CUSTOM_SOURCE_DIR}/cmake/files.cmake)

if(NOT DEFINED ${ATH_BACKEND})
	set(ATH_BACKEND "SDL")
endif()

if(ATH_BACKEND MATCHES "SDL")
	add_subdirectory(${AETHER_SOURCE_DIR}/thirdparty/SDL)
	add_subdirectory(${AETHER_SOURCE_DIR}/thirdparty/SDL_image)
	add_subdirectory(${AETHER_SOURCE_DIR}/thirdparty/SDL_ttf)
	set(AETHER_PLATFORM_SOURCES
		${AETHER_SDL_GRAPHICS_SOURCES}
		${AETHER_SDL_CORE_SOURCES}
		${AETHER_SDL_AUDIO_SOURCES})
	set(AETHER_PLATFORM_INCLUDE_DIRS
		${AETHER_SDL_INCLUDE_DIRS})
elseif(ATH_BACKEND MATCHES "ALLEGRO")

else()
	error("You must set the ATH_BACKEND to a valid value.")
endif()

set(AETHER_ALL_SOURCES ${AETHER_PLATFORM_SOURCES} ${AETHER_COMMON_SOURCES})
set(AETHER_ALL_INCDIRS ${AETHER_PLATFORM_INCDIRS} ${AETHER_COMMON_INCDIRS})

#add_library(aetherstatic STATIC ${AETHER_ALL_SOURCES})
#target_include_directories(aetherstatic "${AETHER_ALL_INCDIRS}")