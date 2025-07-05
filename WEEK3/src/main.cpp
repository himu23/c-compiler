#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/semantic_analyzer.h"

std::string read_file(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Cannot open file " << filename << "\n";
        exit(1);
    }
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./parser <source-file>\n";
        return 1;
    }

    std::string source = read_file(argv[1]);

    Lexer lexer(source);
    auto tokens = lexer.tokenize();

    Parser parser(tokens);
    auto ast = parser.parse();

    if (ast) {
        std::cout << "Parsed AST:\n";
        ast->print(2);

        SemanticAnalyzer analyzer;
        ast->accept(analyzer);

        const auto& errs = analyzer.get_errors();
        if (!errs.empty()) {
            std::cout << "\nSemantic Errors:\n";
            for (const auto& e : errs)
                std::cout << "  " << e << "\n";
        } else {
            std::cout << "\nSemantic Analysis Passed.\n";
        }

    } else {
        std::cout << "No AST generated.\n";
    }

    return 0;
}
