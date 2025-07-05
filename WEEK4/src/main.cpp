#include "../include/lexer.h"
#include "../include/parser.h"
#include "../include/ir_generator.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::string read_file(const std::string& path) {
    std::ifstream f(path);
    if (!f.is_open()) {
        std::cerr << "Error: could not open " << path << "\n";
        exit(1);
    }
    std::stringstream ss;
    ss << f.rdbuf();
    return ss.str();
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: ./irgen <file.c-->\n";
        return 1;
    }

    std::string source_code = read_file(argv[1]);
    Lexer lexer(source_code);
    auto tokens = lexer.tokenize();

    Parser parser(tokens);
    auto ast = parser.parse();

    if (ast) {
        IRGenerator irgen;
        ast->accept(irgen);
        std::cout << "Generated IR:\n";
        irgen.print_ir();
    } else {
        std::cout << "Parsing failed.\n";
    }

    return 0;
}
