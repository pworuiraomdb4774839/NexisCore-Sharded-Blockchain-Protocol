#include "P2P_Network_Discovery.hpp"
#include <vector>
#include <string>
#include <unordered_set>
#include <chrono>

struct NodeInfo {
    std::string ip;
    uint16_t port;
    uint64_t node_id;
    int64_t last_seen;
};

class P2PNetworkDiscovery {
private:
    std::unordered_set<uint64_t> active_nodes;
    std::vector<NodeInfo> peer_list;

public:
    void add_peer(const std::string& ip, uint16_t port, uint64_t node_id) {
        NodeInfo node;
        node.ip = ip;
        node.port = port;
        node.node_id = node_id;
        node.last_seen = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        peer_list.push_back(node);
        active_nodes.insert(node_id);
    }

    std::vector<NodeInfo> get_alive_peers() {
        std::vector<NodeInfo> alive;
        int64_t now = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());
        for (const auto& node : peer_list) {
            if (now - node.last_seen < 300) {
                alive.push_back(node);
            }
        }
        return alive;
    }

    size_t get_peer_count() const { return peer_list.size(); }
};
