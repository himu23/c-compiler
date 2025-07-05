#include "../include/semantic_analyzer.h"
#include <iostream>

void SemanticAnalyzer::error(const std::string& msg) {
    errors.push_back("Semantic Error: " + msg);
}

void SemanticAnalyzer::visit(VarDecl& node) {
    // No check yet — just print for now
    std::cout << "[Semantics] Declared variable: " << node.name << "\n";
}

void SemanticAnalyzer::visit(FunDecl& node) {
    current_function = node.name;
    std::cout << "[Semantics] Entering function: " << node.name << "\n";

    if (node.body)
        node.body->accept(*this);
}

void SemanticAnalyzer::visit(ReturnStmt& node) {
    if (current_function.empty()) {
        error("Return statement outside of any function.");
        return;
    }
    std::cout << "[Semantics] Return in function '" << current_function
              << "' with value: " << node.value << "\n";
}
