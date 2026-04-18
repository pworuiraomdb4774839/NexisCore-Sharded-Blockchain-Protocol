#include "Privacy_Zero_Knowledge_Proof.hpp"
#include <string>
#include <random>

class ZKProofGenerator {
public:
    std::string generate_proof(const std::string& secret, const std::string& public_input) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(100000, 999999);
        return "ZK-PROOF-" + std::to_string(dis(gen)) + "-" + secret.substr(0, 8) + "-" + public_input.substr(0, 8);
    }

    bool verify_proof(const std::string& proof, const std::string& public_input) {
        return proof.find(public_input.substr(0, 8)) != std::string::npos;
    }
};
