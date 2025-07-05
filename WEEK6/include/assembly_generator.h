#ifndef ASSEMBLY_GENERATOR_H
#define ASSEMBLY_GENERATOR_H

#include "ir_instruction.h"
#include <fstream>
#include <map>
#include <vector>

class AssemblyGenerator {
    std::map<std::string, std::string> register_map;
    std::vector<std::string> available_registers = {"rdi", "rsi", "rdx", "rcx", "r8", "r9"};
    std::ofstream output_file;
    int stack_offset = 0;

public:
    AssemblyGenerator();
    void generate_from_ir(const std::vector<IRInstruction>& instructions);
    void emit(const std::string& instr);
    void emit_function_prologue(const std::string& func_name);
    void emit_function_epilogue();
    std::string allocate_register(const std::string& temp);
    void free_register(const std::string& temp);
};

#endif
