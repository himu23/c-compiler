#ifndef AST_H
#define AST_H

#include <iostream>
#include <memory>
#include <string>
#include <vector>

// Forward declare ASTVisitor
class ASTVisitor;

// Base class
class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
    virtual void accept(ASTVisitor& visitor) = 0;
};

// Compound statement
class CompoundStmt : public ASTNode {
public:
    std::vector<std::unique_ptr<ASTNode>> statements;

    void add(std::unique_ptr<ASTNode> stmt) {
        statements.push_back(std::move(stmt));
    }

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "CompoundStmt:\n";
        for (const auto& stmt : statements) {
            stmt->print(indent + 2);
        }
    }

    void accept(ASTVisitor& visitor) override {
        for (auto& stmt : statements) {
            stmt->accept(visitor);
        }
    }
};

// Variable declaration
class VarDecl : public ASTNode {
public:
    std::string type;
    std::string name;

    VarDecl(const std::string& t, const std::string& n) : type(t), name(n) {}

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "VarDecl: " << type << " " << name << "\n";
    }

    void accept(ASTVisitor& visitor) override;
};

// Function declaration
class FunDecl : public ASTNode {
public:
    std::string return_type;
    std::string name;
    std::unique_ptr<CompoundStmt> body;

    FunDecl(const std::string& rt, const std::string& n, std::unique_ptr<CompoundStmt> b)
        : return_type(rt), name(n), body(std::move(b)) {}

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "FunDecl: " << return_type << " " << name << "\n";
        if (body) body->print(indent + 2);
    }

    void accept(ASTVisitor& visitor) override;
};

// Return statement
class ReturnStmt : public ASTNode {
public:
    std::string value;

    ReturnStmt(const std::string& v) : value(v) {}

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "ReturnStmt: " << value << "\n";
    }

    void accept(ASTVisitor& visitor) override;
};

// Visitor interface
class ASTVisitor {
public:
    virtual void visit(VarDecl& node) = 0;
    virtual void visit(FunDecl& node) = 0;
    virtual void visit(ReturnStmt& node) = 0;
    virtual ~ASTVisitor() = default;
};

// Visitor method definitions
inline void VarDecl::accept(ASTVisitor& visitor) { visitor.visit(*this); }
inline void FunDecl::accept(ASTVisitor& visitor) { visitor.visit(*this); }
inline void ReturnStmt::accept(ASTVisitor& visitor) { visitor.visit(*this); }

#endif
