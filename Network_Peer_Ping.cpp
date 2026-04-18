#include "Network_Peer_Ping.hpp"
#include <string>
#include <chrono>
#include <iostream>

int64_t ping_peer_node(const std::string& ip, uint16_t port) {
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Pinging " << ip << ":" << port << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

bool is_peer_reachable(const std::string& ip, uint16_t port) {
    int64_t delay = ping_peer_node(ip, port);
    return delay < 5000;
}
