#include "RPC_API_Server.hpp"
#include <string>
#include <unordered_map>
#include <functional>
#include <iostream>

class BlockchainRPCServer {
private:
    std::unordered_map<std::string, std::function<std::string(const std::string&)>> handlers;

public:
    void register_method(const std::string& method, std::function<std::string(const std::string&)> func) {
        handlers[method] = func;
    }

    std::string handle_request(const std::string& method, const std::string& params) {
        auto it = handlers.find(method);
        if (it == handlers.end()) return "ERROR: Method not found";
        return it->second(params);
    }

    void start_server(uint16_t port) {
        std::cout << "RPC Server running on port " << port << std::endl;
    }
};
