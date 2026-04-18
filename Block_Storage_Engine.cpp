#include "Block_Storage_Engine.hpp"
#include <unordered_map>
#include <string>
#include <vector>
#include <cstdint>

class BlockStorage {
private:
    std::unordered_map<uint64_t, std::string> block_data;
    std::unordered_map<std::string, uint64_t> hash_to_height;

public:
    void save_block(uint64_t height, const std::string& block_hash, const std::string& raw_data) {
        block_data[height] = raw_data;
        hash_to_height[block_hash] = height;
    }

    std::string get_block_by_height(uint64_t height) const {
        auto it = block_data.find(height);
        return (it != block_data.end()) ? it->second : "";
    }

    uint64_t get_height_by_hash(const std::string& hash) const {
        auto it = hash_to_height.find(hash);
        return (it != hash_to_height.end()) ? it->second : 0;
    }
};
