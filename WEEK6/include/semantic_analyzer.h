#ifndef SEMANTIC_ANALYZER_H
#define SEMANTIC_ANALYZER_H

#include "ast.h"
#include <vector>
#include <string>
#include <unordered_map>
#include <memory>

class SemanticAnalyzer : public ASTVisitor {
    std::vector<std::string> errors;
    std::string current_function;

public:
    void visit(VarDecl& node) override;
    void visit(FunDecl& node) override;
    void visit(ReturnStmt& node) override;
    void visit(CompoundStmt& node) override; // added this

    const std::vector<std::string>& get_errors() const { return errors; }

private:
    void error(const std::string& msg);
};

#endif
