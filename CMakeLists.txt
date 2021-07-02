cmake_minimum_required(VERSION 3.18.8)

project(gameConnect LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)

find_package(gRPC REQUIRED Config)
add_subdirectory(server)
add_subdirectory(serviceClient)

function(my_export_target _target _include_dir)
    file(
        WRITE "${CMAKE_CURRENT_BINARY_DIR}/${_target}Config.cmake"
        "
        set(gameConnect_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/server/include;${CMAKE_CURRENT_LIST_DIR}/serviceClient/include)
        if(NOT gRPC)
          find_package(gRPC)
        endif()
        include(\"\$\{CMAKE_CURRENT_LIST_DIR\}/${_target}Targets.cmake\")
        "
    )

    export(TARGETS server serviceClient FILE "${CMAKE_CURRENT_BINARY_DIR}/${_target}Targets.cmake")

    # The following call can pollute your PC's CMake package registry
    #       See comments/alternatives below
    export(PACKAGE ${_target})
endfunction(my_export_target)

my_export_target(gameConnect "${CMAKE_CURRENT_SOURCE_DIR}")

