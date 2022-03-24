#include "../include/gameConnect_server/gameConnect_server.hpp"
#include <grpc/grpc.h>
#include <grpc++/grpc++.h>
#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/impl/codegen/service_type.h>

namespace GameConnect {

GameConnectServer::GameConnectServer(std::string address) : address_(std::move(address)), builder_(std::make_unique<grpc::ServerBuilder>()) {
    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
}

auto GameConnectServer::registerService(std::unique_ptr<grpc::Service>&& service) -> void {
    builder_->RegisterService(service.get());
    services_.push_back(std::move(service));
}

auto GameConnectServer::run() -> void {
    builder_->AddListeningPort(address_, grpc::InsecureServerCredentials());
    server_ = builder_->BuildAndStart();

    // other thread must be responsible for shutting down the server for this call to ever return.
    server_->Wait();
}

auto GameConnectServer::shutdown() -> void {
    server_->Shutdown();
}

}
