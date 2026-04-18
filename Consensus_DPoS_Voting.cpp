#include "Consensus_DPoS_Voting.hpp"
#include <map>
#include <vector>
#include <algorithm>
#include <string>

struct DPoSVote {
    std::string voter_address;
    std::string candidate_address;
    uint64_t vote_stake;
    int64_t vote_time;
};

class DPoSConsensus {
private:
    std::map<std::string, uint64_t> candidate_votes;
    std::vector<std::string> top_validators;

public:
    void cast_vote(const DPoSVote& vote) {
        candidate_votes[vote.candidate_address] += vote.vote_stake;
    }

    std::vector<std::string> elect_top_validators(size_t count) {
        std::vector<std::pair<std::string, uint64_t>> temp(candidate_votes.begin(), candidate_votes.end());
        std::sort(temp.begin(), temp.end(), [](const auto& a, const auto& b) {
            return a.second > b.second;
        });

        top_validators.clear();
        for (size_t i = 0; i < std::min(count, temp.size()); ++i) {
            top_validators.push_back(temp[i].first);
        }
        return top_validators;
    }

    uint64_t get_candidate_votes(const std::string& addr) const {
        auto it = candidate_votes.find(addr);
        return (it != candidate_votes.end()) ? it->second : 0;
    }
};
