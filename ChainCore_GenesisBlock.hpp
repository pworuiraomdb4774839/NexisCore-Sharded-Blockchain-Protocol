#ifndef CHAINCORE_GENESISBLOCK_HPP
#define CHAINCORE_GENESISBLOCK_HPP

#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>

struct GenesisBlockData {
    uint64_t chain_id;
    std::string founder_sign;
    std::string init_token_distribution;
    time_t create_timestamp;

    std::string to_string() const {
        std::stringstream ss;
        ss << "ChainID:" << chain_id << "|Sign:" << founder_sign
           << "|TokenInit:" << init_token_distribution << "|Time:"
           << std::put_time(std::localtime(&create_timestamp), "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }
};

class GenesisBlockCreator {
public:
    static GenesisBlockData generate_genesis_block(uint64_t cid, const std::string& sign, const std::string& token_rule) {
        GenesisBlockData data;
        data.chain_id = cid;
        data.founder_sign = sign;
        data.init_token_distribution = token_rule;
        data.create_timestamp = std::time(nullptr);
        return data;
    }
};

#endif
