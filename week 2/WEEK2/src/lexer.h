#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    DELIMITER,
    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;
    int line;
    int column;

    Token(TokenType type, const std::string& value, int line, int column)
        : type(type), value(value), line(line), column(column) {}
};

class Lexer {
public:
    Lexer(const std::string& sourceCode);
    std::vector<Token> tokenize();

private:
    std::string source;
    size_t pos;
    int line, column;

    char peek() const;
    char peek_char() const;
    char advance();
    void skipWhitespace();
    Token readIdentifierOrKeyword();
    Token readNumber();
};

// utility for printing token type
inline std::string token_type_to_string(TokenType type) {
    switch (type) {
        case TokenType::KEYWORD: return "KEYWORD";
        case TokenType::IDENTIFIER: return "IDENTIFIER";
        case TokenType::NUMBER: return "NUMBER";
        case TokenType::OPERATOR: return "OPERATOR";
        case TokenType::DELIMITER: return "DELIMITER";
        case TokenType::END_OF_FILE: return "EOF";
        default: return "UNKNOWN";
    }
}

#endif // LEXER_H
