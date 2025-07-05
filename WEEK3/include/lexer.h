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
    int line;
    int column;

    Token(TokenType t, std::string v, int l, int c)
        : type(t), value(v), line(l), column(c) {}
};

class Lexer {
public:
    Lexer(const std::string& source);
    std::vector<Token> tokenize();

private:
    std::string src;
    size_t pos;
    int line, column;

    char peek();
    char advance();
    void skip_whitespace();
    Token read_identifier();
    Token read_number();
    Token read_operator_or_delimiter();
    bool is_keyword(const std::string& word);
};

#endif
