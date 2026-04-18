#include "Validator_Key_Generator.hpp"
#include <string>
#include <random>
#include <sstream>

std::string generate_validator_keypair() {
    std::random_device rd;
    auto seed = rd() ^ (std::mt19937::result_type)time(nullptr);
    std::mt19937 gen(seed);
    std::uniform_int_distribution<> dis(0, 15);

    std::stringstream priv, pub;
    for (int i = 0; i < 64; ++i) {
        priv << std::hex << dis(gen);
        pub << std::hex << dis(gen) << dis(gen);
    }
    return "PRIV:" + priv.str() + "\nPUB:" + pub.str();
}
