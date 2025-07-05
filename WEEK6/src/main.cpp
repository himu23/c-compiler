#include "lexer.h"
#include "parser.h"
#include "ir_generator.h"
#include "assembly_generator.h"
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
        std::cerr << "Usage: ./codegen <file.c-->\n";
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

        std::vector<IRInstruction> ir = irgen.get_instructions();  // Add getter if needed
        AssemblyGenerator codegen;
        codegen.generate_from_ir(ir);
        std::cout << "Assembly code generated to output.s\n";
    } else {
        std::cout << "Parsing failed.\n";
    }

    return 0;
}
