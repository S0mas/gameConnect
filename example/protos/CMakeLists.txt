project(protos)

find_package(protobuf CONFIG REQUIRED)
find_package(gRPC CONFIG REQUIRED)

#PREPARING PROTO FILES ##########################################################
file(GLOB_RECURSE PROTO_FILES protos/*.proto)

# Add Library target with protobuf sources
add_library(${PROJECT_NAME} ${PROTO_FILES} ${PROTOBUF_INCLUDE_DIRS})
target_link_libraries(${PROJECT_NAME}
    ${Protobuf_LIBRARIES}
    gRPC::grpc
    gRPC::grpc++
    gRPC::grpc++_reflection
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${CMAKE_CURRENT_BINARY_DIR}
)

get_target_property(grpc_cpp_plugin_location gRPC::grpc_cpp_plugin LOCATION)
protobuf_generate(TARGET ${PROJECT_NAME} LANGUAGE cpp)
protobuf_generate(TARGET ${PROJECT_NAME} LANGUAGE grpc GENERATE_EXTENSIONS .grpc.pb.h .grpc.pb.cc PLUGIN "protoc-gen-grpc=${grpc_cpp_plugin_location}")
