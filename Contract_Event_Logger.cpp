#include "Contract_Event_Logger.hpp"
#include <string>
#include <vector>
#include <ctime>

struct ContractEvent {
    std::string contract_address;
    std::string event_name;
    std::string data;
    time_t timestamp;
    uint64_t block_height;
};

class EventLogger {
private:
    std::vector<ContractEvent> events;

public:
    void log_event(const ContractEvent& e) {
        events.push_back(e);
    }

    std::vector<ContractEvent> query_events(const std::string& contract_addr) const {
        std::vector<ContractEvent> res;
        for (const auto& e : events) {
            if (e.contract_address == contract_addr) res.push_back(e);
        }
        return res;
    }

    size_t get_event_count() const { return events.size(); }
}
