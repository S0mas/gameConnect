#pragma once
#include <gameConnect_serviceClient/gameConnect_serviceClient.hpp>
#include <protos/Authorization.grpc.pb.h>
#include <loguru/loguru.hpp>

class Authorization : public ServiceClient<authorization::Authorization> {
    void log(std::string message) override {
        LOG_F(INFO, "%s", message.c_str());
    }
    void logError(std::string message) override {
        LOG_F(ERROR, "%s", message.c_str());
    }
public:
    Authorization() {}
    Authorization(std::shared_ptr<::grpc::ChannelInterface> channel) : ServiceClient(channel) {}
    auto Login(authorization::LoginRequest const& request) {
        return call<authorization::LoginRequest, authorization::Token>(&STUB_TYPE::Login, request);
    }
    auto Register(authorization::RegisterRequest const& request) {
        return call<authorization::RegisterRequest, google::protobuf::Empty>(&STUB_TYPE::Register, request);
    }
    auto RemindPassword(authorization::RemindPasswordRequest const& request) {
        return call<authorization::RemindPasswordRequest, google::protobuf::Empty>(&STUB_TYPE::RemindPassword, request);
    }
};
