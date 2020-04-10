cmake_minimum_required(VERSION 2.8.11)

project(aether)

include(cmake/Build.cmake)
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}/cmake")

set(AETHER_SOURCES_DIR "${CMAKE_CURRENT_LIST_DIR}/src/aether")
set(RZTL_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/module/rztl/include")

# SOURCES DEFINITION *********************************************************************
file(GLOB AETHER_COMMON_MODULE
    "${AETHER_SOURCES_DIR}/*.h"
    "${AETHER_SOURCES_DIR}/*.cpp"
    "${AETHER_SOURCES_DIR}/core/*.h"
    "${AETHER_SOURCES_DIR}/core/*.cpp"
    "${AETHER_SOURCES_DIR}/math/*.h"
    "${AETHER_SOURCES_DIR}/math/*.cpp"
    "${AETHER_SOURCES_DIR}/graphics/*.h"
    "${AETHER_SOURCES_DIR}/graphics/*.cpp"
    "${AETHER_SOURCES_DIR}/audio/*.h"
    "${AETHER_SOURCES_DIR}/audio/*.cpp")
file(GLOB AETHER_MAP_MODULE
    "${AETHER_SOURCES_DIR}/map/*.h"
    "${AETHER_SOURCES_DIR}/map/*.cpp")
file(GLOB AETHER_ALLEGRO_SOURCES
    "${AETHER_SOURCES_DIR}/audio/allegro/*.h"
    "${AETHER_SOURCES_DIR}/audio/allegro/*.cpp"
    "${AETHER_SOURCES_DIR}/core/allegro/*.h"
    "${AETHER_SOURCES_DIR}/core/allegro/*.cpp"
    "${AETHER_SOURCES_DIR}/graphics/allegro/*.h"
    "${AETHER_SOURCES_DIR}/graphics/allegro/*.cpp")
file(GLOB AETHER_SDL_SOURCES
    "${AETHER_SOURCES_DIR}/audio/sdl/*.h"
    "${AETHER_SOURCES_DIR}/audio/sdl/*.cpp"
    "${AETHER_SOURCES_DIR}/core/sdl/*.h"
    "${AETHER_SOURCES_DIR}/core/sdl/*.cpp"
    "${AETHER_SOURCES_DIR}/graphics/sdl/*.h"
    "${AETHER_SOURCES_DIR}/graphics/sdl/*.cpp")
file(GLOB AETHER_DUMMY_SOURCES
    "${AETHER_SOURCES_DIR}/audio/dummy/*.h"
    "${AETHER_SOURCES_DIR}/audio/dummy/*.cpp"
    "${AETHER_SOURCES_DIR}/core/dummy/*.h"
    "${AETHER_SOURCES_DIR}/core/dummy/*.cpp"
    "${AETHER_SOURCES_DIR}/graphics/dummy/*.h"
    "${AETHER_SOURCES_DIR}/graphics/dummy/*.cpp")
file(GLOB_RECURSE RZTL_SOURCES
    "${RZTL_INCLUDE_DIR}/**/*.h"
    "${RZTL_INCLUDE_DIR}/**/*.cpp")

# SOURCES PREPARATION *********************************************************************
list(APPEND AETHER_SOURCES ${AETHER_COMMON_MODULE} ${RZTL_SOURCES})
if(${AETHER_USE_ALLEGRO})
    find_package(Allegro REQUIRED)
    list(APPEND AETHER_SOURCES ${AETHER_ALLEGRO_SOURCES})
elseif(${AETHER_USE_SDL})

	if(WIN32 AND MSVC)
		set(SDL2_PATH           ${CMAKE_CURRENT_LIST_DIR}/module/sdl/SDL2-2.0.10/)
		set(SDL2_IMAGE_PATH     ${CMAKE_CURRENT_LIST_DIR}/module/sdl/SDL2_image-2.0.5/)
		set(SDL2_TTF_PATH       ${CMAKE_CURRENT_LIST_DIR}/module/sdl/SDL2_ttf-2.0.15/)
    endif()
	
	find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_ttf REQUIRED)

    #set(SDL2_INCLUDE_DIR ${CMAKE_CURRENT_LIST_DIR}/module/sdl/SDL2-2.0.10/include)
    #set(SDL2_LIBRARIES
    #    ${CMAKE_CURRENT_LIST_DIR}/module/sdl/SDL2-2.0.10/include
    #    ${CMAKE_CURRENT_LIST_DIR}/module/sdl/SDL2-2.0.10/include
    #    ${CMAKE_CURRENT_LIST_DIR}/module/sdl/SDL2-2.0.10/include
    #)
    list(APPEND AETHER_SOURCES ${AETHER_SDL_SOURCES})
elseif(${AETHER_USE_DUMMY})
    list(APPEND AETHER_SOURCES ${AETHER_DUMMY_SOURCES})
endif()
if(${AETHER_USE_MAP})
    find_package(tmxparser REQUIRED)
    list(APPEND AETHER_SOURCES ${AETHER_MAP_MODULE})
endif()

# LIB CREATION ****************************************************************************
add_library(aether-lib ${AETHER_SOURCES})

# LIB LINK AND INCLUDES *******************************************************************
target_include_directories(aether-lib PUBLIC ${RZTL_INCLUDE_DIR})
if(${AETHER_USE_ALLEGRO})
    target_include_directories(aether-lib PUBLIC ${ALLEGRO_INCLUDE_DIR})
    target_link_libraries(aether-lib PUBLIC ${ALLEGRO_LIBRARIES})
    target_compile_definitions(aether-lib PUBLIC AETHER_USE_ALLEGRO=1)
elseif(${AETHER_USE_SDL})
    target_compile_definitions(aether-lib PUBLIC AETHER_USE_SDL=1)
    target_link_libraries(aether-lib SDL2::Main)
    target_link_libraries(aether-lib SDL2::TTF)
    target_link_libraries(aether-lib SDL2::Image)
    include_directories(${SDL2_INCLUDE_DIR})
    include_directories(${SDL2_TTF_INCLUDE_DIR})
    include_directories(${SDL2_IMAGE_INCLUDE_DIR})
elseif(${AETHER_USE_DUMMY})
    target_compile_definitions(aether-lib PUBLIC AETHER_USE_DUMMY=1)
endif()
if(${AETHER_USE_MAP})
    target_include_directories(aether-lib PUBLIC ${TMXPARSER_INCLUDE_DIR})
    target_link_libraries(aether-lib PUBLIC ${TMXPARSER_LIBRARY})
endif()

set_target_properties(aether-lib PROPERTIES
                COMPILE_FLAGS "-g -std=c++11"
                LINK_FLAGS "-g -ftest-coverage -fprofile-arcs")

get_directory_property(hasParent PARENT_DIRECTORY)

set(AETHER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src")

if(hasParent)
    set(AETHER_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/src" PARENT_SCOPE)
endif()

message("Aether include directory: ${AETHER_INCLUDE_DIR}")

if(WIN32)
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin/win32)
elseif(UNIX)
    set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin/linux)
endif()

if(${AETHER_BUILD_EXAMPLES})
    ADD_AETHER_TARGET(aether-minimal-example examples/basic/main.cpp)
    ADD_AETHER_TARGET(aether-texture-example examples/texture/main.cpp)
    ADD_AETHER_TARGET(aether-input-example examples/input/main.cpp)
endif()

#target_link_libraries(aether-lib PUBLIC tmxparser)

#[[
if(MSVC)
	set( CMAKE_C_FLAGS_RELEASE "/MT /O2 /Ob2 /D NDEBUG" )
	set( CMAKE_CXX_FLAGS_RELEASE "/MT /O2 /Ob2 /D NDEBUG" )
	set( CMAKE_C_FLAGS_DEBUG "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1" )
	set( CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1" )
endif()
]]
