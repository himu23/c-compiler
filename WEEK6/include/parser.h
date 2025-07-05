#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ast.h"
#include <memory>
#include <vector>

class Parser {
    const std::vector<Token>& tokens;
    int current;

public:
    Parser(const std::vector<Token>& tokens);
    std::unique_ptr<ASTNode> parse();

private:
    const Token& peek();
    const Token& advance();
    bool match(TokenType type);
    void error(const std::string& msg);
};

#endif
