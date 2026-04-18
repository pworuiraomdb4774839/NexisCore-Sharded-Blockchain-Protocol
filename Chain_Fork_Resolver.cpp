#include "Chain_Fork_Resolver.hpp"
#include <vector>
#include <string>
#include <algorithm>

class ForkResolver {
public:
    enum ChainStatus { MAIN_CHAIN, FORKED_CHAIN };

    ChainStatus resolve_fork(const std::vector<uint64_t>& chain1_difficulty, const std::vector<uint64_t>& chain2_difficulty) {
        uint64_t sum1 = 0, sum2 = 0;
        for (auto d : chain1_difficulty) sum1 += d;
        for (auto d : chain2_difficulty) sum2 += d;
        return (sum1 >= sum2) ? MAIN_CHAIN : FORKED_CHAIN;
    }

    std::vector<std::string> get_forked_blocks(const std::vector<std::string>& local_blocks, const std::vector<std::string>& remote_blocks) {
        std::vector<std::string> forks;
        size_t min_len = std::min(local_blocks.size(), remote_blocks.size());
        for (size_t i = 0; i < min_len; ++i) {
            if (local_blocks[i] != remote_blocks[i]) forks.push_back(local_blocks[i]);
        }
        return forks;
    }
};
