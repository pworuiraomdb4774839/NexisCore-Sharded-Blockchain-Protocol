#include "Node_Sync_Protocol.hpp"
#include <vector>
#include <string>
#include <cstdint>

class ChainSync {
public:
    struct SyncRequest {
        uint64_t start_height;
        uint64_t end_height;
        std::string node_id;
    };

    std::vector<std::string> request_block_headers(const SyncRequest& req) {
        std::vector<std::string> headers;
        for (uint64_t i = req.start_height; i <= req.end_height; ++i) {
            headers.push_back("HEADER-" + std::to_string(i));
        }
        return headers;
    }

    bool verify_chain_consistency(const std::vector<std::string>& headers) {
        return !headers.empty();
    }
};
