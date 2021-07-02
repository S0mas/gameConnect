#pragma once
#include <loguru/loguru.hpp>
#include "../../include/example_service/authorization/authorization.hpp"

grpc::Status AuthorizationServiceImpl::Login(grpc::ServerContext* context, const authorization::LoginRequest* request, authorization::Token* reply) {
    LOG_F(INFO, "%s| login: %s, password: %s", __func__, request->email().c_str(), request->password().c_str());
    reply->set_token(std::string(234, 'X'));
    return grpc::Status::OK;
}
grpc::Status AuthorizationServiceImpl::Register(grpc::ServerContext* context, const authorization::RegisterRequest* request, google::protobuf::Empty* reply) {
    LOG_F(INFO, "%s|", __func__);
    return grpc::Status::OK;
}

grpc::Status AuthorizationServiceImpl::RemindPassword(grpc::ServerContext* context, const authorization::RemindPasswordRequest* request, google::protobuf::Empty* reply) {
    LOG_F(INFO, "%s|", __func__);
    return grpc::Status::OK;
}
