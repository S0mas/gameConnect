project(example_service)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h src/*.hpp)

add_library(${PROJECT_NAME} ${SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
    loguru
    protos
)

target_include_directories(${PROJECT_NAME}
    PRIVATE src
    PUBLIC include
)
