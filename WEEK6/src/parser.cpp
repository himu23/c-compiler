#include "parser.h"
#include <iostream>

Parser::Parser(const std::vector<Token>& tokens) : tokens(tokens), current(0) {}

const Token& Parser::peek() {
    return tokens[current];
}

const Token& Parser::advance() {
    return tokens[current++];
}

bool Parser::match(TokenType type) {
    if (static_cast<size_t>(current) < tokens.size() && tokens[current].type == type){
        advance();
        return true;
    }
    return false;
}

void Parser::error(const std::string& msg) {
    const Token& tok = peek();
    std::cerr << "Syntax Error at line " << tok.line << ", col " << tok.column << ": " << msg << "\n";
}



std::unique_ptr<ASTNode> Parser::parse() {
    // Step 1: Match type keyword (int/void)
    if (!match(TokenType::KEYWORD)) {
        error("Expected type keyword");
        return nullptr;
    }
    std::string type = tokens[current - 1].value;

    // Step 2: Match identifier (function name)
    if (!match(TokenType::IDENTIFIER)) {
        error("Expected function or variable name");
        return nullptr;
    }
    std::string name = tokens[current - 1].value;

    // Step 3: Is it a function declaration? Match '(' ')'
    if (!match(TokenType::DELIMITER)) {
        error("Expected '(' after function name");
        return nullptr;
    }
    if (tokens[current - 1].value != "(") {
        error("Expected '(' after function name");
        return nullptr;
    }

    if (!match(TokenType::DELIMITER) || tokens[current - 1].value != ")") {
        error("Expected ')' after '('");
        return nullptr;
    }

    // Step 4: Match function body: '{'
    if (!match(TokenType::DELIMITER) || tokens[current - 1].value != "{") {
        error("Expected '{' to start function body");
        return nullptr;
    }

    // Step 5: Parse function body statements
    auto compound = std::make_unique<CompoundStmt>();

    while (peek().type != TokenType::END_OF_FILE &&
           !(peek().type == TokenType::DELIMITER && peek().value == "}")) {

        // Handle return statements: return <identifier> ;
        if (peek().type == TokenType::KEYWORD && peek().value == "return") {
            advance(); // consume "return"

            if (!match(TokenType::IDENTIFIER)) {
                error("Expected identifier after return");
                return nullptr;
            }
            std::string val = tokens[current - 1].value;

            if (!match(TokenType::DELIMITER) || tokens[current - 1].value != ";") {
                error("Expected ';' after return statement");
                return nullptr;
            }

            compound->add(std::make_unique<ReturnStmt>(val));
        } else {
            error("Unknown or unsupported statement in function body");
            advance(); // skip invalid
        }
    }

    // Step 6: Match closing '}'
    if (!match(TokenType::DELIMITER) || tokens[current - 1].value != "}") {
        error("Expected '}' to close function body");
        return nullptr;
    }

    // Final: Build function AST
    return std::make_unique<FunDecl>(type, name, std::move(compound));
}

