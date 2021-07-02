project(loguru)

add_library(${PROJECT_NAME} src/loguru.cpp)

target_include_directories(${PROJECT_NAME}
    PRIVATE src
    PUBLIC include
)
