#pragma once
#include <memory>
#include <string>
#include <vector>

namespace grpc {
    class Service;
    class ServerBuilder;
};

class GameConnectServer {
    std::vector<std::unique_ptr<grpc::Service>> services_;
    std::string address_;
    std::unique_ptr<grpc::ServerBuilder> builder_;
public:
    GameConnectServer(std::string address = "localhost");
    void run();
    void registerService(std::unique_ptr<grpc::Service>&&);
};


