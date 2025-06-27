#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& sourceCode)
    : source(sourceCode), pos(0), line(1), column(1) {}

char Lexer::peek() const {
    if (pos >= source.size()) return '\0';
    return source[pos];
}

char Lexer::advance() {
    char current = peek();
    pos++;
    if (current == '\n') {
        line++;
        column = 1;
    } else {
        column++;
    }
    return current;
}

void Lexer::skipWhitespace() {
    while (isspace(peek())) advance();
}

Token Lexer::readIdentifierOrKeyword() {
    int startCol = column;
    std::string value;
    while (isalnum(peek()) || peek() == '_') {
        value += advance();
    }
    TokenType type = TokenType::IDENTIFIER;
    if (value == "int" || value == "void" || value == "if" ||
        value == "else" || value == "while" || value == "return" ||
        value == "input" || value == "output") {
        type = TokenType::KEYWORD;
    }
    return Token(type, value, line, startCol);
}

Token Lexer::readNumber() {
    int startCol = column;
    std::string value;
    while (isdigit(peek())) {
        value += advance();
    }
    return Token(TokenType::NUMBER, value, line, startCol);
}

std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (peek() != '\0') {
        skipWhitespace();
        char ch = peek();
        if (isalpha(ch) || ch == '_') {
            tokens.push_back(readIdentifierOrKeyword());
        } else if (isdigit(ch)) {
            tokens.push_back(readNumber());
        } else {
            // Skipping operators & delimiters for now
            advance();
        }
    }
    tokens.push_back(Token(TokenType::END_OF_FILE, "EOF", line, column));
    return tokens;
}
