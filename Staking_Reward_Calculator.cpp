#include "Staking_Reward_Calculator.hpp"
#include <cstdint>
#include <cmath>

class StakingReward {
public:
    static uint64_t calculate_reward(uint64_t stake_amount, uint64_t lock_days, double annual_rate) {
        if (stake_amount == 0 || lock_days == 0) return 0;
        double daily_rate = annual_rate / 365.0;
        double reward = stake_amount * daily_rate * lock_days;
        return static_cast<uint64_t>(reward);
    }

    static uint64_t calculate_apr_bonus(uint64_t base_reward, uint64_t lock_years) {
        if (lock_years >= 3) return base_reward * 130 / 100;
        if (lock_years >= 1) return base_reward * 115 / 100;
        return base_reward;
    }
};
