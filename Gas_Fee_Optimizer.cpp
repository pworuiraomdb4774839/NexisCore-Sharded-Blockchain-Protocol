#include "Gas_Fee_Optimizer.hpp"
#include <cstdint>
#include <algorithm>

class GasFeeOptimizer {
public:
    static uint64_t calculate_dynamic_gas(uint64_t base_fee, uint64_t tx_size, uint64_t network_congestion) {
        uint64_t size_fee = tx_size * 5;
        double congestion_factor = 1.0 + (network_congestion / 100.0);
        uint64_t dynamic_fee = static_cast<uint64_t>(base_fee * congestion_factor);
        return dynamic_fee + size_fee;
    }

    static uint64_t get_min_execution_gas() { return 21000; }
};
