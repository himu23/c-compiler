#include "../include/lexer.h"  //as its in different folder now
#include <cctype>
#include <unordered_set>

Lexer::Lexer(const std::string& source) : src(source), pos(0), line(1), column(1) {}

char Lexer::peek() {
    return pos < src.size() ? src[pos] : '\0';
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

void Lexer::skip_whitespace() {
    while (isspace(peek())) advance();
}

bool Lexer::is_keyword(const std::string& word) {
    static std::unordered_set<std::string> keywords = {
        "int", "void", "if", "else", "while", "return", "input", "output"
    };
    return keywords.count(word);
}

Token Lexer::read_identifier() {
    int start_col = column;
    std::string value;
    while (isalnum(peek()) || peek() == '_') {
        value += advance();
    }
    return Token(is_keyword(value) ? TokenType::KEYWORD : TokenType::IDENTIFIER, value, line, start_col);
}

Token Lexer::read_number() {
    int start_col = column;
    std::string value;
    while (isdigit(peek())) {
        value += advance();
    }
    return Token(TokenType::NUMBER, value, line, start_col);
}

Token Lexer::read_operator_or_delimiter() {
    int start_col = column;
    char current = advance();
    std::string value(1, current);

    // Two-character operators: ==, !=, <=, >=
    if ((current == '=' || current == '!' || current == '<' || current == '>') && peek() == '=') {
        value += advance();
        return Token(TokenType::OPERATOR, value, line, start_col);
    }

    // Single-character operators
    static std::unordered_set<char> operators = {'+', '-', '*', '/', '=', '<', '>', '!'};
    static std::unordered_set<char> delimiters = {'{', '}', '(', ')', '[', ']', ';', ','};

    if (operators.count(current)) {
        return Token(TokenType::OPERATOR, value, line, start_col);
    }
    if (delimiters.count(current)) {
        return Token(TokenType::DELIMITER, value, line, start_col);
    }

    // Unknown character (treat as operator fallback)
    return Token(TokenType::OPERATOR, value, line, start_col);
}


std::vector<Token> Lexer::tokenize() {
    std::vector<Token> tokens;
    while (pos < src.size()) {
        skip_whitespace();
        char c = peek();
        if (isalpha(c) || c == '_') {
            tokens.push_back(read_identifier());
        } else if (isdigit(c)) {
            tokens.push_back(read_number());
        } else if (ispunct(c)) {
            tokens.push_back(read_operator_or_delimiter());
        } else {
            advance();  // skip unknown
        }
    }
    tokens.push_back(Token(TokenType::END_OF_FILE, "", line, column));
    return tokens;
}
