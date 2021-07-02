project(example_server)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h src/*.hpp)

add_executable(${PROJECT_NAME} ${SOURCES})

include_directories(${gameConnect_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC
    example_service
    server
    loguru
)

target_include_directories(${PROJECT_NAME}
    PRIVATE src
    PUBLIC include
)
