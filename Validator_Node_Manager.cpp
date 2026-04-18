#include "Validator_Node_Manager.hpp"
#include <vector>
#include <string>
#include <unordered_set>

struct Validator {
    std::string address;
    uint64_t stake;
    bool is_active;
    int64_t last_block_time;
};

class ValidatorManager {
private:
    std::vector<Validator> validators;
    std::unordered_set<std::string> jailed_addresses;

public:
    void register_validator(const Validator& v) {
        validators.push_back(v);
    }

    bool jail_validator(const std::string& addr) {
        if (jailed_addresses.count(addr)) return false;
        jailed_addresses.insert(addr);
        return true;
    }

    std::vector<Validator> get_active_validators() const {
        std::vector<Validator> res;
        for (const auto& v : validators) {
            if (v.is_active && !jailed_addresses.count(v.address)) res.push_back(v);
        }
        return res;
    }
};
