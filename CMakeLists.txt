cmake_minimum_required(VERSION 3.0.0)

project(aether)

set(BUILD_SHARED_LIBS FALSE)
add_subdirectory(module/raylib)
include(cmake/files.cmake)

file(GLOB_RECURSE SECS_SOURCES
	module/secs/src/lib/**.h
	module/secs/src/lib/**.cpp
)

set(SECS_INCS
	module/secs/src/lib)

file(GLOB_RECURSE HADRON_SOURCES
	module/hadron/src/lib/**.h
	module/hadron/src/lib/**.cpp
)

set(HADRON_INCS
	module/hadron/src/lib)

file(GLOB ASTARCPP_SOURCES
	module/astarcpp/src/*.h)

set(ASTARCPP_INCS
	module/astarcpp/src)

file(GLOB AETHER_SOURCES
	src/aether/**/raylib/**.cpp
	src/aether/*/*.h
	src/aether/*/*.cpp
	src/aether/*.cpp
	src/aether/*.hpp
	src/aether/*.h
)

add_library(aether STATIC ${AETHER_SOURCES})


message("SECS SOURCES:\n${SECS_SOURCES}\n")
message("SECS INCS:\n${SECS_INCS}\n")

message("HADRON SOURCES:\n${HADRON_SOURCES}\n")
message("HADRON INCS:\n${HADRON_INCS}\n")

message("ASTAR SOURCES:\n${ASTARCPP_SOURCES}\n")
message("ASTAR INCS:\n${ASTARCPP_INCS}\n")

message("AETHER SOURCES:\n${AETHER_SOURCES}\n")

#[===[

set(CMAKE_MODULE_PATH "${AETHER_SOURCE_DIR}/cmake")


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

]===]
