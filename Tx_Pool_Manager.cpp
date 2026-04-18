#include "Tx_Pool_Manager.hpp"
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

struct Transaction {
    std::string tx_id;
    std::string from_addr;
    std::string to_addr;
    uint64_t amount;
    uint64_t gas_fee;
    int64_t timestamp;
};

struct TxComparator {
    bool operator()(const Transaction& a, const Transaction& b) {
        return a.gas_fee < b.gas_fee;
    }
};

class TransactionPool {
private:
    std::priority_queue<Transaction, std::vector<Transaction>, TxComparator> pending_txs;
    const size_t max_pool_size = 10240;

public:
    bool add_transaction(const Transaction& tx) {
        if (pending_txs.size() >= max_pool_size) return false;
        pending_txs.push(tx);
        return true;
    }

    Transaction get_highest_priority_tx() {
        if (pending_txs.empty()) return {};
        Transaction tx = pending_txs.top();
        pending_txs.pop();
        return tx;
    }

    size_t get_pool_size() const { return pending_txs.size(); }
};
