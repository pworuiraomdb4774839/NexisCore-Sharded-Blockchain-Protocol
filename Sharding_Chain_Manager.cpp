#include "Sharding_Chain_Manager.hpp"
#include <vector>
#include <string>
#include <unordered_map>

class ShardingManager {
private:
    std::unordered_map<uint32_t, std::vector<std::string>> shard_nodes;

public:
    void create_shard(uint32_t shard_id) {
        shard_nodes[shard_id] = {};
    }

    void assign_node_to_shard(uint32_t shard_id, const std::string& node_id) {
        shard_nodes[shard_id].push_back(node_id);
    }

    std::vector<std::string> get_shard_nodes(uint32_t shard_id) const {
        auto it = shard_nodes.find(shard_id);
        return (it != shard_nodes.end()) ? it->second : std::vector<std::string>();
    }

    size_t get_shard_count() const { return shard_nodes.size(); }
};
