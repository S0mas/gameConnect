cmake_minimum_required(VERSION 3.18.8)

project(gameConnect LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
include(C:/D/Programowanie/libs/vcpkg/scripts/buildsystems/vcpkg.cmake)
find_package(gRPC REQUIRED Config)
add_subdirectory(gameConnect_server)
add_subdirectory(gameConnect_serviceClient)
add_subdirectory(protos)
message(${CMAKE_CURRENT_BINARY_DIR})
function(my_export_target _target _include_dir)
    file(
        WRITE "${CMAKE_CURRENT_BINARY_DIR}/${_target}Config.cmake"
        "
        set(gameConnect_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/gameConnect_server/include;${CMAKE_CURRENT_LIST_DIR}/gameConnect_serviceClient/include)
        if(NOT gRPC)
          find_package(gRPC)
        endif()
        include(\"\$\{CMAKE_CURRENT_LIST_DIR\}/${_target}Targets.cmake\")
        "
    )
    file(
        WRITE "C:/D/Programowanie/libs/vcpkg/scripts/buildsystems/${_target}Config.cmake"
        "
        set(gameConnect_INCLUDE_DIRS ${CMAKE_CURRENT_LIST_DIR}/gameConnect_server/include;${CMAKE_CURRENT_LIST_DIR}/gameConnect_serviceClient/include)
        if(NOT gRPC)
            find_package(gRPC)
        endif()
        include(\"\$\{CMAKE_CURRENT_LIST_DIR\}/${_target}Targets.cmake\")
        "
    )

    export(TARGETS gameConnect_server gameConnect_serviceClient FILE "${CMAKE_CURRENT_BINARY_DIR}/${_target}Targets.cmake")
    export(PACKAGE ${_target})
endfunction(my_export_target)

my_export_target(gameConnect "${CMAKE_CURRENT_SOURCE_DIR}")

