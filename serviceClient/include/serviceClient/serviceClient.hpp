#pragma once
#include <memory>
#include <string>
#include <optional>
#include <variant>
#include <grpc/grpc.h>

#include <grpc++/channel.h>
#include <grpc++/client_context.h>
#include <grpc++/create_channel.h>

template<typename ResponseType>
struct Response {
    std::optional<ResponseType> response_;
    std::optional<std::string> errorMsg_;
    std::optional<int> errorCode_;
    Response(ResponseType const& response) : response_(response) {}
    Response(int const errorCode, std::string const& errorMsg) {
        errorCode_ = errorCode;
        errorMsg_ = errorMsg;
    }
};

template<typename ServiceType>
class ServiceClient {
    std::shared_ptr<::grpc::ChannelInterface> channel_;
    template<typename RequestType, typename ResponseType>
    using ServiceMemberFunctionType = grpc::Status(ServiceType::Stub::*)(grpc::ClientContext*, RequestType const&, ResponseType*);
    auto stub() const noexcept {
        static ServiceType::Stub stub_{channel_};
        return stub_;
    }
protected:
    grpc::ClientContext context_;
    virtual void log(std::string message) {}
    virtual void logError(std::string message) {}
public:
    template<typename RequestType, typename ResponseType>
    auto call(ServiceMemberFunctionType<RequestType, ResponseType> function, RequestType const& request)  {
        log("REQUEST DATA:\n" + std::string(request.DebugString().c_str()));
        ResponseType reply;    
        auto status = (stub().*function)(&context_, request, &reply);
        if(status.ok()) {
            log("RESPONSE DATA:\n" + std::string(reply.DebugString().c_str()));
            return Response<ResponseType>(reply);
        }
        else {
            logError("error_code: " + std::to_string(status.error_code()) + ", error_message: " + std::string(status.error_message()));
            return Response<ResponseType>(status.error_code(), status.error_message());
        }
    }
    using STUB_TYPE = typename ServiceType::Stub;
    ServiceClient() : channel_(createLocalChannel()) {}
    ServiceClient(std::shared_ptr<::grpc::ChannelInterface> channel) : channel_(channel) {}
    static std::shared_ptr<::grpc::ChannelInterface> createLocalChannel() {
        //SetEnvironmentVariable("GRPC_DEFAULT_SSL_ROOTS_FILE_PATH", "roots.pem");
        //static std::shared_ptr<::grpc::ChannelInterface> CHANNEL = grpc::CreateChannel("1.1.1.1:1",  grpc::InsecureChannelCredentials());
        return grpc::CreateChannel("localhost", grpc::InsecureChannelCredentials());
    }
};

template<typename ServiceType>
class AuthorizedClient : public ServiceClient<ServiceType> {
public:
    AuthorizedClient() : ServiceClient<ServiceType>() {}
    AuthorizedClient(std::shared_ptr<::grpc::ChannelInterface> channel) : ServiceClient<ServiceType>(channel) {}
    void setToken(std::string token) {
        this->context_.AddMetadata("authorization", token);
    }
    std::string token() const noexcept {
        return this->context_.GetMetadata("authorization");
    }
};
