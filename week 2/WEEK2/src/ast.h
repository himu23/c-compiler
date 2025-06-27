#ifndef AST_H
#define AST_H

#include <iostream>
#include <memory>
#include <string>

class ASTNode {
public:
    virtual ~ASTNode() = default;
    virtual void print(int indent = 0) const = 0;
};

using ASTPtr = std::shared_ptr<ASTNode>;

class Number : public ASTNode {
public:
    std::string value;
    Number(const std::string& val) : value(val) {}

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "Number(" << value << ")\n";
    }
};

class BinaryOp : public ASTNode {
public:
    std::string op;
    ASTPtr left, right;

    BinaryOp(const std::string& o, ASTPtr l, ASTPtr r)
        : op(o), left(l), right(r) {}

    void print(int indent = 0) const override {
        std::cout << std::string(indent, ' ') << "BinaryOp(" << op << ")\n";
        left->print(indent + 2);
        right->print(indent + 2);
    }
};

#endif
