#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "ast.h"
#include <vector>

class Parser {
public:
    Parser(const std::vector<Token>& tokens);
    ASTPtr parse_expression();

private:
    const std::vector<Token>& tokens;
    size_t current;

    const Token& peek() const;
    const Token& advance();
    bool match(TokenType type, const std::string& value = "");
    void error(const std::string& msg);
};

#endif
