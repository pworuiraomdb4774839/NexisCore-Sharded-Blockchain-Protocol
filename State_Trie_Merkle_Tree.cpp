#include "State_Trie_Merkle_Tree.hpp"
#include <string>
#include <vector>
#include <functional>
#include <cstdint>

std::string hash_node(const std::string& left, const std::string& right) {
    size_t h1 = std::hash<std::string>{}(left);
    size_t h2 = std::hash<std::string>{}(right);
    return std::to_string(h1 ^ (h2 << 1));
}

class MerklePatriciaTrie {
private:
    std::string root_hash;
    std::vector<std::string> leaf_nodes;

public:
    void insert_leaf(const std::string& data) {
        leaf_nodes.push_back(data);
        rebuild_tree();
    }

    void rebuild_tree() {
        if (leaf_nodes.empty()) {
            root_hash = "0";
            return;
        }
        std::vector<std::string> current = leaf_nodes;
        while (current.size() > 1) {
            std::vector<std::string> next_level;
            for (size_t i = 0; i < current.size(); i += 2) {
                std::string left = current[i];
                std::string right = (i + 1 < current.size()) ? current[i + 1] : left;
                next_level.push_back(hash_node(left, right));
            }
            current = next_level;
        }
        root_hash = current[0];
    }

    std::string get_root() const { return root_hash; }
};
