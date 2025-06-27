#include "parser.h"
#include <iostream>

Parser::Parser(const std::vector<Token>& t) : tokens(t), current(0) {}

const Token& Parser::peek() const {
    return tokens[current];
}

const Token& Parser::advance() {
    return tokens[current++];
}

bool Parser::match(TokenType type, const std::string& value) {
    if (peek().type == type && (value.empty() || peek().value == value)) {
        advance();
        return true;
    }
    return false;
}

void Parser::error(const std::string& msg) {
    std::cerr << "Parse error at line " << peek().line
              << ", col " << peek().column << ": " << msg << "\n";
    exit(1);
}

// For now: expression = NUMBER | ( expression + expression )
ASTPtr Parser::parse_expression() {
    if (match(TokenType::DELIMITER, "(")) {
        ASTPtr left = parse_expression();
        std::string op = advance().value;  // +, -, etc.
        ASTPtr right = parse_expression();
        if (!match(TokenType::DELIMITER, ")")) {
            error("Expected ')'");
        }
        return std::make_shared<BinaryOp>(op, left, right);
    }
    else if (peek().type == TokenType::NUMBER) {
        std::string val = advance().value;
        return std::make_shared<Number>(val);
    }

    error("Invalid expression");
    return nullptr;
}
