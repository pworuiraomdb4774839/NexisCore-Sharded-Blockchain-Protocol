#include "Account_Balance_Tracker.hpp"
#include <unordered_map>
#include <string>
#include <cstdint>

class AccountManager {
private:
    std::unordered_map<std::string, uint64_t> balances;

public:
    void create_account(const std::string& address, uint64_t init_balance = 0) {
        if (balances.find(address) == balances.end()) {
            balances[address] = init_balance;
        }
    }

    bool transfer(const std::string& from, const std::string& to, uint64_t amount) {
        if (balances[from] < amount) return false;
        balances[from] -= amount;
        balances[to] += amount;
        return true;
    }

    uint64_t get_balance(const std::string& address) const {
        auto it = balances.find(address);
        return (it != balances.end()) ? it->second : 0;
    }
};
