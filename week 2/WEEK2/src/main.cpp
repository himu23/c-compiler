#include "lexer.h"
#include "parser.h"
#include <fstream>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: ./parser <file>\n";
        return 1;
    }

    std::ifstream file(argv[1]);
    if (!file) {
        std::cerr << "File not found.\n";
        return 1;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();
    Lexer lexer(buffer.str());
    auto tokens = lexer.tokenize();
    for (const auto& tok : tokens) {
        std::cout << "Token: " << token_type_to_string(tok.type) << " (" << tok.value << ")\n";
    }
    Parser parser(tokens);
    auto ast = parser.parse_expression();

    std::cout << "AST:\n";
    ast->print();

    return 0;
}
