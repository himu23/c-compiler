#include <iostream>
#include <fstream>
#include <sstream>
#include "lexer.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./lexer <source.c-->\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    std::stringstream buffer;
    buffer << file.rdbuf();

    Lexer lexer(buffer.str());
    std::vector<Token> tokens = lexer.tokenize();

    for (const auto& token : tokens) {
        std::cout << "Token: " << static_cast<int>(token.type)
                  << " (" << token.value << ") at line " << token.line
                  << ", col " << token.column << std::endl;
    }

    return 0;
}
