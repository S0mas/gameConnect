#include "../include/server/server.hpp"
#include <grpc/grpc.h>
#include <grpc++/grpc++.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/impl/codegen/service_type.h>

GameConnectServer::GameConnectServer(std::string address) : address_(std::move(address)), builder_(std::make_unique<grpc::ServerBuilder>()) {
    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
}

void GameConnectServer::registerService(std::unique_ptr<grpc::Service>&& service) {
    builder_->RegisterService(service.get());
    services_.push_back(std::move(service));
}

void GameConnectServer::run() {
    builder_->AddListeningPort(address_, grpc::InsecureServerCredentials());
    std::unique_ptr<grpc::Server> server(builder_->BuildAndStart());

    // other thread must be responsible for shutting down the server for this call to ever return.
    server->Wait();
}
