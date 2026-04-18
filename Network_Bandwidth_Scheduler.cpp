#include "Network_Bandwidth_Scheduler.hpp"
#include <vector>
#include <string>
#include <algorithm>

class BandwidthScheduler {
public:
    struct NodeBandwidth {
        std::string node_id;
        uint64_t max_bandwidth;
        uint64_t used_bandwidth;
    };

    void allocate_bandwidth(NodeBandwidth& node, uint64_t required) {
        if (node.used_bandwidth + required <= node.max_bandwidth) {
            node.used_bandwidth += required;
        }
    }

    std::vector<NodeBandwidth> sort_by_available_bw(std::vector<NodeBandwidth> nodes) {
        std::sort(nodes.begin(), nodes.end(), [](const auto& a, const auto& b) {
            return (a.max_bandwidth - a.used_bandwidth) > (b.max_bandwidth - b.used_bandwidth);
        });
        return nodes;
    }
};
