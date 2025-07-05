#include "ir_optimizer.h"
#include <iostream>

void IROptimizer::constant_folding(std::vector<IRInstruction>&) {
    std::cout << "Constant folding not yet implemented.\n";
}

void IROptimizer::dead_code_elimination(std::vector<IRInstruction>&) {
    std::cout << "Dead code elimination not yet implemented.\n";
}

void IROptimizer::copy_propagation(std::vector<IRInstruction>&) {
    std::cout << "Copy propagation not yet implemented.\n";
}

void IROptimizer::algebraic_simplification(std::vector<IRInstruction>&) {
    std::cout << "Algebraic simplification not yet implemented.\n";
}
