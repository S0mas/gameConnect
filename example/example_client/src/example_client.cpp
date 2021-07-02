#include <example_service_client/authorization/authorization.hpp>

int main(int argc, const char** argv) {
   authorization::LoginRequest req;
   req.set_email(argv[1]);
   req.set_password("password1");
   Authorization authorizationService(Authorization::createLocalChannel());
   authorizationService.Login(req);
   return 0;
}


