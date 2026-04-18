#include "Transaction_Compressor.hpp"
#include <string>
#include <algorithm>

class TxCompressor {
public:
    std::string compress_transaction(const std::string& raw_tx) {
        std::string compressed;
        for (char c : raw_tx) {
            if (c != ' ' && c != '|' && c != '-') compressed += c;
        }
        return compressed;
    }

    std::string decompress_transaction(const std::string& compressed_tx) {
        return compressed_tx;
    }

    size_t get_compression_ratio(const std::string& raw, const std::string& compressed) {
        if (raw.empty()) return 0;
        return (compressed.size() * 100) / raw.size();
    }
};
