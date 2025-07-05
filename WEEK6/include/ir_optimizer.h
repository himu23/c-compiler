#ifndef IR_OPTIMIZER_H
#define IR_OPTIMIZER_H

#include "ir_instruction.h"
#include <vector>

class IROptimizer {
public:
    // include/ir_optimizer.h
    void constant_folding(std::vector<IRInstruction>& instructions);
    void dead_code_elimination(std::vector<IRInstruction>& instructions);
    void copy_propagation(std::vector<IRInstruction>& instructions);
    void algebraic_simplification(std::vector<IRInstruction>& instructions);
};

#endif
