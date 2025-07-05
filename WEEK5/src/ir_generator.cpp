#include "../include/ir_generator.h"
#include <iostream>

std::string IRGenerator::new_temp() {
    return "t" + std::to_string(temp_counter++);
}

std::string IRGenerator::new_label() {
    return "L" + std::to_string(label_counter++);
}

void IRGenerator::emit(OpCode op, std::string result, std::string arg1, std::string arg2) {
    instructions.emplace_back(op, result, arg1, arg2);
}

void IRGenerator::print_ir() const {
    for (const auto& instr : instructions) {
        std::cout << instr.to_string() << "\n";
    }
}

// ---------- Visitor Implementations ----------

void IRGenerator::visit(FunDecl& node) {
    emit(OpCode::FUNCTION_BEGIN, "", node.name);
    if (node.body)
        node.body->accept(*this);
    emit(OpCode::FUNCTION_END);
}

void IRGenerator::visit(CompoundStmt& node) {
    for (auto& stmt : node.statements) {
        stmt->accept(*this);
    }
}

void IRGenerator::visit(ReturnStmt& node) {
    emit(OpCode::RETURN, "", node.value);  // 'value' should be a string for now (e.g., "x")
}

void IRGenerator::visit(VarDecl& node) {
    // Optional: could emit a declaration, but currently not needed
}

const std::vector<IRInstruction>& IRGenerator::get_instructions() const {
    return instructions;
}
