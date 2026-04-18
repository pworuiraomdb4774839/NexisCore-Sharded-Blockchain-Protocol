#ifndef BLOCK_HEADER_STRUCT_HPP
#define BLOCK_HEADER_STRUCT_HPP

#include <string>
#include <cstdint>
#include <ctime>

struct BlockHeader {
    uint64_t block_height;
    std::string prev_block_hash;
    std::string merkle_root;
    uint64_t nonce;
    uint64_t difficulty;
    time_t timestamp;
    std::string miner_address;

    std::string serialize_header() const {
        return std::to_string(block_height) + "|" + prev_block_hash + "|" + merkle_root +
               "|" + std::to_string(nonce) + "|" + std::to_string(difficulty) +
               "|" + std::to_string(timestamp) + "|" + miner_address;
    }
};

#endif
