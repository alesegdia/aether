cmake_minimum_required(VERSION 2.8.11)

project(aether)

list(APPEND CMAKE_CXX_FLAGS "-std=c++11 -g -ftest-coverage -fprofile-arcs")

file(GLOB_RECURSE AETHER_SRCS "src/*.cpp" "src/*.h")

# to be set from the outside when calling cmake command
set(AETHER_USE_ALLEGRO TRUE)

if(${AETHER_USE_ALLEGRO})
    add_definitions(-DAETHER_USE_ALLEGRO)
    function(ADD_AETHER_TARGET EXEC-NAME SRCS)
            add_executable(${EXEC-NAME} ${AETHER_SRCS} ${SRCS})
            target_include_directories(${EXEC-NAME} PUBLIC src)
            set_target_properties(${EXEC-NAME} PROPERTIES
                    COMPILE_FLAGS "-std=c++11"
                    LINK_FLAGS "-g -ftest-coverage -fprofile-arcs"
                    )
            if(WIN32)
                    target_link_libraries(${EXEC-NAME} allegro_monolith)
            elseif(UNIX)
                    target_link_libraries(${EXEC-NAME} allegro)
                    target_link_libraries(${EXEC-NAME} allegro_image)
                    target_link_libraries(${EXEC-NAME} allegro_primitives)
                    target_link_libraries(${EXEC-NAME} allegro_font)
                    target_link_libraries(${EXEC-NAME} allegro_ttf)
                    target_link_libraries(${EXEC-NAME} allegro_audio)
                    target_link_libraries(${EXEC-NAME} allegro_acodec)
            else()
                    message(SEND_FATAL "Unknown platform")
            endif()
    endfunction(ADD_AETHER_TARGET)
endif()

if(WIN32)
        list(APPEND CMAKE_EXE_LINKER_FLAGS "-static-libstdc++ -static-libgcc")
        set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin/win32)
elseif(UNIX)
        set(EXECUTABLE_OUTPUT_PATH ${CMAKE_HOME_DIRECTORY}/bin/linux)
endif()

ADD_AETHER_TARGET(aether-minimal-example examples/basic/main.cpp)
ADD_AETHER_TARGET(aether-texture-example examples/texture/main.cpp)
ADD_AETHER_TARGET(aether-input-example examples/input/main.cpp)

