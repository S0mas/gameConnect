project(gameConnect_server)

add_library(${PROJECT_NAME} src/gameConnect_server.cpp)
add_library(gameConnect::${PROJECT_NAME} ALIAS ${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME} PUBLIC
    gRPC::grpc
    gRPC::grpc++
    gRPC::grpc++_reflection
)

target_include_directories(${PROJECT_NAME} INTERFACE
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME}>
    $<INSTALL_INTERFACE:include/${PROJECT_NAME}>)

set_target_properties(${PROJECT_NAME} PROPERTIES
  PUBLIC_HEADER "gameConnect_server.hpp")

install(TARGETS ${PROJECT_NAME}
  EXPORT gameConnectTargets
  RUNTIME DESTINATION "${INSTALL_BIN_DIR}" COMPONENT bin
  LIBRARY DESTINATION "${INSTALL_LIB_DIR}" COMPONENT lib
  PUBLIC_HEADER DESTINATION "${INSTALL_INCLUDE_DIR}/gameConnect_server"
    COMPONENT dev)
