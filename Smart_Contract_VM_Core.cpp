#include "Smart_Contract_VM_Core.hpp"
#include <string>
#include <vector>
#include <unordered_map>
#include <cstdint>

enum VMOpCode {
    OP_ADD, OP_SUB, OP_MUL, OP_STORE, OP_LOAD, OP_TRANSFER
};

class ContractVM {
private:
    std::unordered_map<uint32_t, uint64_t> memory;
    uint64_t gas_used;

public:
    ContractVM() : gas_used(0) {}

    void execute_opcode(VMOpCode op, uint64_t a, uint64_t b) {
        gas_used += 100;
        switch(op) {
            case OP_ADD: memory[0] = a + b; break;
            case OP_SUB: memory[0] = (a > b) ? (a - b) : 0; break;
            case OP_MUL: memory[0] = a * b; break;
            default: break;
        }
    }

    uint64_t get_gas_used() const { return gas_used; }
    uint64_t read_memory(uint32_t addr) const { return memory.at(addr); }
};
