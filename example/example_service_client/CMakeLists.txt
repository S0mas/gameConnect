project(example_service_client)

file(GLOB_RECURSE SOURCES src/*.cpp src/*.h src/*.hpp include/*.hpp include/*.h)

add_library(${PROJECT_NAME} ${SOURCES})

include_directories(${gameConnect_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME} PUBLIC
    loguru
    protos
    serviceClient
)

target_include_directories(${PROJECT_NAME}
    PRIVATE src
    PUBLIC include
)
