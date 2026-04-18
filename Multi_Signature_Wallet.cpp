#include "Multi_Signature_Wallet.hpp"
#include <vector>
#include <string>
#include <unordered_set>

class MultiSigWallet {
private:
    std::vector<std::string> owners;
    uint8_t required_signatures;

public:
    MultiSigWallet(const std::vector<std::string>& owners_list, uint8_t required)
        : owners(owners_list), required_signatures(required) {}

    bool validate_transaction(const std::vector<std::string>& signers) {
        std::unordered_set<std::string> valid_signers;
        for (const auto& s : signers) {
            for (const auto& o : owners) {
                if (s == o) valid_signers.insert(s);
            }
        }
        return valid_signers.size() >= required_signatures;
    }

    size_t get_owner_count() const { return owners.size(); }
};
