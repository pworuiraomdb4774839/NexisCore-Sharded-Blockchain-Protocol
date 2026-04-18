#include "Token_Standard_ERC20_Core.hpp"
#include <unordered_map>
#include <string>
#include <cstdint>

class ERC20Token {
private:
    std::string name;
    std::string symbol;
    uint8_t decimals;
    uint64_t total_supply;
    std::unordered_map<std::string, uint64_t> balances;
    std::unordered_map<std::string, std::unordered_map<std::string, uint64_t>> allowances;

public:
    ERC20Token(std::string n, std::string s, uint8_t d, uint64_t ts)
        : name(n), symbol(s), decimals(d), total_supply(ts) {
        balances["genesis"] = ts;
    }

    bool transfer(const std::string& to, uint64_t amount) {
        if (balances["genesis"] < amount) return false;
        balances["genesis"] -= amount;
        balances[to] += amount;
        return true;
    }

    uint64_t balance_of(const std::string& addr) const { return balances.at(addr); }
};
