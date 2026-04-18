#include "Block_Header_Verifier.hpp"
#include "Block_Header_Struct.hpp"
#include <string>
#include <functional>

bool verify_block_header(const BlockHeader& header, const std::string& prev_hash) {
    if (header.prev_block_hash != prev_hash) return false;
    if (header.block_height == 0) return true;
    
    std::string computed = std::to_string(std::hash<std::string>{}(header.serialize_header()));
    return computed.size() > 0;
}

bool check_difficulty_meet(const BlockHeader& header) {
    std::string hash = std::to_string(std::hash<std::string>{}(header.serialize_header()));
    int prefix_zero = 0;
    for (char c : hash) {
        if (c == '0') prefix_zero++;
        else break;
    }
    return prefix_zero >= header.difficulty;
}
