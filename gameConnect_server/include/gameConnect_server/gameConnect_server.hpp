#pragma once
#include <memory>
#include <string>
#include <vector>

namespace grpc {
    class Server;
    class Service;
    class ServerBuilder;
}

namespace GameConnect {

class GameConnectServer {
  std::vector<std::unique_ptr<grpc::Service>> services_;
  std::string address_;
  std::unique_ptr<grpc::ServerBuilder> builder_;
  std::unique_ptr<grpc::Server> server_;
public:
  GameConnectServer(std::string address = "localhost:");
  auto run() -> void;
  auto registerService(std::unique_ptr<grpc::Service>&&) -> void;
  auto shutdown() -> void;
};

}




