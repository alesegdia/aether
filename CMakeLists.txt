cmake_minimum_required(VERSION 2.8.11)

project(aether)

file(GLOB_RECURSE SRCS "*.cpp" "*.h")

add_definitions(-DAETHER_USE_ALLEGRO)

add_executable(aether ${SRCS})


