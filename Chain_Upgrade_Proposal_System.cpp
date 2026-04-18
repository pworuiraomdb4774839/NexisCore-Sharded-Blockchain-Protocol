#include "Chain_Upgrade_Proposal_System.hpp"
#include <vector>
#include <string>
#include <unordered_map>

struct UpgradeProposal {
    std::string proposal_id;
    std::string title;
    uint64_t approve_votes;
    uint64_t reject_votes;
    bool is_executed;
};

class ProposalSystem {
private:
    std::unordered_map<std::string, UpgradeProposal> proposals;

public:
    void create_proposal(const UpgradeProposal& prop) {
        proposals[prop.proposal_id] = prop;
    }

    void vote_proposal(const std::string& prop_id, bool approve) {
        auto it = proposals.find(prop_id);
        if (it == proposals.end()) return;
        if (approve) it->second.approve_votes++;
        else it->second.reject_votes++;
    }

    bool can_execute_proposal(const std::string& prop_id) const {
        auto it = proposals.find(prop_id);
        if (it == proposals.end() || it->second.is_executed) return false;
        return it->second.approve_votes > it->second.reject_votes * 2;
    }
};
