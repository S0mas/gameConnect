#include <example_service/authorization/authorization.hpp>
#include <gameConnect_server/gameConnect_server.hpp>

int main() {
    GameConnectServer server;
    server.registerService(std::make_unique<AuthorizationServiceImpl>());
    server.run();
    return 0;
}
