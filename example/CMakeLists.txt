cmake_minimum_required(VERSION 3.18)

project("example" LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
add_compile_options("$<$<CONFIG:RELEASE>:/O2>")

find_package(gameConnect)

add_subdirectory(example_server)
add_subdirectory(example_client)
add_subdirectory(example_service)
add_subdirectory(example_service_client)
add_subdirectory(loguru)
add_subdirectory(protos)

