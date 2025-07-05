#ifndef COMPILER_DRIVER_H
#define COMPILER_DRIVER_H

#include "lexer.h"
#include "parser.h"
#include "semantic_analyzer.h"
#include "ir_generator.h"
#include "assembly_generator.h"
#include "ir_optimizer.h"
#include <string>
#include <memory>

class CompilerDriver {
    std::unique_ptr<Lexer> lexer;
    std::unique_ptr<Parser> parser;
    std::unique_ptr<SemanticAnalyzer> analyzer;
    std::unique_ptr<IRGenerator> ir_generator;
    std::unique_ptr<IROptimizer> optimizer;
    std::unique_ptr<AssemblyGenerator> codegen;

    bool debug_mode = false;
    int optimization_level = 0;
    bool print_stages = false;

public:
    bool compile(const std::string& source_file, const std::string& output_file);
    void set_optimization_level(int level);
    void enable_debug_info(bool enable);
    void print_compilation_stages(bool enable);
};

#endif
