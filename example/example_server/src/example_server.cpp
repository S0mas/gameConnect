#include <example_service/authorization/authorization.hpp>
#include <server/server.hpp>

int main() {
    GameConnectServer server;
    server.registerService(std::make_unique<AuthorizationServiceImpl>());
    server.run();
    return 0;
}
