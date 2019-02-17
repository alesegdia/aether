
set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_LIST_DIR}" ${CMAKE_MODULE_PATH})

function(ADD_AETHER_TARGET EXEC-NAME SRCS)
    add_executable(${EXEC-NAME} "${SRCS}")
    set_target_properties(${EXEC-NAME} PROPERTIES
                    COMPILE_FLAGS "-g -std=c++14"
                    LINK_FLAGS "-g -ftest-coverage -fprofile-arcs"
                    )

    target_link_libraries(${EXEC-NAME} aether-allegro)
    target_include_directories(${EXEC-NAME} PUBLIC "${AETHER_INCLUDE_DIR}")
    target_include_directories(${EXEC-NAME} PUBLIC "${RZTL_INCLUDE_DIR}")
endfunction(ADD_AETHER_TARGET)
