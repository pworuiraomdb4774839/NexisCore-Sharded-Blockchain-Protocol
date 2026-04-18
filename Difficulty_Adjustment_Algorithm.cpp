#include "Difficulty_Adjustment_Algorithm.hpp"
#include <cstdint>
#include <cmath>

class DifficultyAdjust {
public:
    static uint64_t adjust_difficulty(uint64_t current_diff, int64_t actual_time, int64_t target_block_time) {
        if (actual_time < target_block_time / 2) return current_diff * 2;
        if (actual_time > target_block_time * 2) return current_diff / 2;
        
        double ratio = static_cast<double>(actual_time) / target_block_time;
        uint64_t new_diff = static_cast<uint64_t>(current_diff * ratio);
        return new_diff < 1 ? 1 : new_diff;
    }
};
