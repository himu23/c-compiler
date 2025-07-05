#ifndef IR_GENERATOR_H
#define IR_GENERATOR_H

#include "ast.h"
#include "ir_instruction.h"
#include <vector>

class IRGenerator : public ASTVisitor {
    std::vector<IRInstruction> instructions;
    int temp_counter = 0;
    int label_counter = 0;

public:
    std::string new_temp();
    std::string new_label();
    void emit(OpCode op, std::string result = "", std::string arg1 = "", std::string arg2 = "");

    void print_ir() const;

    // ASTVisitor overrides
    void visit(FunDecl& node) override;
    void visit(CompoundStmt& node) override;
    void visit(ReturnStmt& node) override;
    void visit(VarDecl& node) override;
};

#endif
