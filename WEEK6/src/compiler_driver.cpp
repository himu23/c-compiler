#include "compiler_driver.h"
#include <fstream>
#include <iostream>

bool CompilerDriver::compile(const std::string& source_file, const std::string& output_file) {
    std::ifstream file(source_file);
    if (!file) {
        std::cerr << "Error: Cannot open " << source_file << "\n";
        return false;
    }

    std::string source((std::istreambuf_iterator<char>(file)),
                        std::istreambuf_iterator<char>());

    lexer = std::make_unique<Lexer>(source);
    auto tokens = lexer->tokenize();

    parser = std::make_unique<Parser>(tokens);
    auto ast = parser->parse();

    analyzer = std::make_unique<SemanticAnalyzer>();
    ast->accept(*analyzer);

    if (!analyzer->get_errors().empty()) {
        std::cerr << "Semantic errors found:\n";
        for (const auto& err : analyzer->get_errors()) {
            std::cerr << "  " << err << "\n";
        }
        return false;
    }

    ir_generator = std::make_unique<IRGenerator>();
    ast->accept(*ir_generator);

    optimizer = std::make_unique<IROptimizer>();
    optimizer->constant_folding(ir_generator->get_instructions());

    codegen = std::make_unique<AssemblyGenerator>();
    codegen->generate_from_ir(ir_generator->get_instructions());

    std::ofstream out(output_file);
    if (!out) {
        std::cerr << "Error: Cannot write to " << output_file << "\n";
        return false;
    }

    // out << codegen->get_output();  // assuming AssemblyGenerator has a `get_output()` string method
    return true;
}

void CompilerDriver::set_optimization_level(int level) {
    optimization_level = level;
}

void CompilerDriver::enable_debug_info(bool enable) {
    debug_mode = enable;
}

void CompilerDriver::print_compilation_stages(bool enable) {
    print_stages = enable;
}
