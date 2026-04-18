#include "Chain_Analytics_Metrics.hpp"
#include <vector>
#include <cstdint>
#include <cmath>

class ChainMetrics {
public:
    static double calculate_tps(const std::vector<uint64_t>& tx_counts, uint64_t duration_seconds) {
        if (duration_seconds == 0) return 0.0;
        uint64_t total = 0;
        for (auto c : tx_counts) total += c;
        return static_cast<double>(total) / duration_seconds;
    }

    static uint64_t get_avg_block_size(const std::vector<uint64_t>& block_sizes) {
        if (block_sizes.empty()) return 0;
        uint64_t sum = 0;
        for (auto s : block_sizes) sum += s;
        return sum / block_sizes.size();
    }
};
