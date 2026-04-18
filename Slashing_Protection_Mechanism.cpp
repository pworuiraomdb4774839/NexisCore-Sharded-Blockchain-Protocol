#include "Slashing_Protection_Mechanism.hpp"
#include <string>
#include <unordered_map>
#include <cstdint>

class SlashingProtection {
private:
    std::unordered_map<std::string, uint64_t> penalty_records;

public:
    uint64_t calculate_slashing_penalty(const std::string& validator_addr, uint64_t stake, int offense_count) {
        uint64_t penalty = stake * (offense_count * 10) / 100;
        penalty_records[validator_addr] += penalty;
        return penalty;
    }

    bool is_validator_jailed(const std::string& validator_addr) const {
        auto it = penalty_records.find(validator_addr);
        return (it != penalty_records.end() && it->second > 50);
    }
};
