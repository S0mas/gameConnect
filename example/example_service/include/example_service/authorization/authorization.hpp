#pragma once
#include <grpc++/grpc++.h>
#include <protos/authorization.grpc.pb.h>

class AuthorizationServiceImpl final : public authorization::Authorization::Service {
    grpc::Status Login(grpc::ServerContext* context, const authorization::LoginRequest* request, authorization::Token* reply) override;
    grpc::Status Register(grpc::ServerContext* context, const authorization::RegisterRequest* request, google::protobuf::Empty* reply) override;
    grpc::Status RemindPassword(grpc::ServerContext* context, const authorization::RemindPasswordRequest* request, google::protobuf::Empty* reply) override;
};

