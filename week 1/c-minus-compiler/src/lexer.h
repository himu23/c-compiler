#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>

enum class TokenType {
    KEYWORD, IDENTIFIER, NUMBER,
    OPERATOR, DELIMITER,
    END_OF_FILE
};

struct Token {
    TokenType type;
    std::string value;
    int line, column;

    Token(TokenType t, std::string val, int ln, int col)
        : type(t), value(std::move(val)), line(ln), column(col) {}
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
    char advance();
    void skipWhitespace();
    Token readIdentifierOrKeyword();
    Token readNumber();
};

#endif
