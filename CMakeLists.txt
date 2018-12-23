cmake_minimum_required(VERSION 2.8.11)

project(aether)

include(cmake/Build.cmake)

set(AETHER_SOURCES_DIR "${CMAKE_CURRENT_LIST_DIR}/src/aether")
set(RZTL_INCLUDE_DIR "${CMAKE_CURRENT_LIST_DIR}/module/rztl/include")
file(GLOB_RECURSE RZTL_SOURCES
    "${RZTL_INCLUDE_DIR}/**/*.h"
    "${RZTL_INCLUDE_DIR}/**/*.cpp")

find_package(Allegro REQUIRED)

file(GLOB AETHER_COMMON_SOURCES
    "${AETHER_SOURCES_DIR}/*.h"
    "${AETHER_SOURCES_DIR}/*.cpp"
    "${AETHER_SOURCES_DIR}/audio/*.h"
    "${AETHER_SOURCES_DIR}/audio/*.cpp"
    "${AETHER_SOURCES_DIR}/core/*.h"
    "${AETHER_SOURCES_DIR}/core/*.cpp"
    "${AETHER_SOURCES_DIR}/graphics/*.h"
    "${AETHER_SOURCES_DIR}/graphics/*.cpp"
    "${AETHER_SOURCES_DIR}/math/*.h"
    "${AETHER_SOURCES_DIR}/math/*.cpp"
	"${AETHER_SOURCES_DIR}/collision/*.h"
	"${AETHER_SOURCES_DIR}/collision/*.cpp"
	"${AETHER_SOURCES_DIR}/scene/*.h"
	"${AETHER_SOURCES_DIR}/scene/*.cpp"
	"${AETHER_SOURCES_DIR}/map/*.h"
	"${AETHER_SOURCES_DIR}/map/*.cpp"
	)

file(GLOB AETHER_ALLEGRO_SOURCES
    "${AETHER_SOURCES_DIR}/audio/allegro/*.h"
    "${AETHER_SOURCES_DIR}/audio/allegro/*.cpp"
    "${AETHER_SOURCES_DIR}/core/allegro/*.h"
    "${AETHER_SOURCES_DIR}/core/allegro/*.cpp"
    "${AETHER_SOURCES_DIR}/graphics/allegro/*.h"
    "${AETHER_SOURCES_DIR}/graphics/allegro/*.cpp"
    "${AETHER_SOURCES_DIR}/math/allegro/*.h"
    "${AETHER_SOURCES_DIR}/math/allegro/*.cpp"
    )

add_library(aether-allegro ${AETHER_COMMON_SOURCES} ${AETHER_ALLEGRO_SOURCES} ${RZTL_SOURCES})
target_link_libraries(aether-allegro PUBLIC
    ${ALLEGRO_LIBRARIES})

target_include_directories(aether-allegro PUBLIC
    ${ALLEGRO_INCLUDE_DIR}
    ${RZTL_INCLUDE_DIR})

target_compile_definitions(aether-allegro PUBLIC AETHER_USE_ALLEGRO=1)
set_target_properties(aether-allegro PROPERTIES
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

ADD_AETHER_TARGET(aether-minimal-example examples/basic/main.cpp)
ADD_AETHER_TARGET(aether-texture-example examples/texture/main.cpp)
ADD_AETHER_TARGET(aether-input-example examples/input/main.cpp)

#[[
if(MSVC)
	set( CMAKE_C_FLAGS_RELEASE "/MT /O2 /Ob2 /D NDEBUG" )
	set( CMAKE_CXX_FLAGS_RELEASE "/MT /O2 /Ob2 /D NDEBUG" )
	set( CMAKE_C_FLAGS_DEBUG "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1" )
	set( CMAKE_CXX_FLAGS_DEBUG "/D_DEBUG /MTd /Zi /Ob0 /Od /RTC1" )
endif()
]]
