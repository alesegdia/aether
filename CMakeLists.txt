cmake_minimum_required(VERSION 2.8.11)

project(aether)

include(cmake/Build.cmake)

ADD_AETHER_TARGET(aether-minimal-example examples/basic/main.cpp)
ADD_AETHER_TARGET(aether-texture-example examples/texture/main.cpp)
ADD_AETHER_TARGET(aether-input-example examples/input/main.cpp)

