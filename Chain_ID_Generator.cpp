#include "Chain_ID_Generator.hpp"
#include <string>
#include <cstdint>
#include <ctime>

uint64_t generate_numeric_chain_id() {
    time_t now = time(nullptr);
    return static_cast<uint64_t>(now) % 90000000 + 10000000;
}

std::string generate_chain_symbol(uint64_t chain_id) {
    std::string sym = "CHX-";
    sym += std::to_string(chain_id % 10000);
    return sym;
}

std::string generate_full_chain_identifier() {
    uint64_t id = generate_numeric_chain_id();
    return "CHAIN-" + std::to_string(id) + "-" + generate_chain_symbol(id);
}
