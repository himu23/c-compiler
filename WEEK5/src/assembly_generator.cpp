#include "../include/assembly_generator.h"
#include <iostream>

AssemblyGenerator::AssemblyGenerator() {
    output_file.open("output.s");
    if (!output_file.is_open()) {
        std::cerr << "Error opening output.s for writing.\n";
        exit(1);
    }
}

void AssemblyGenerator::emit(const std::string& instr) {
    output_file << instr << "\n";
}

void AssemblyGenerator::emit_function_prologue(const std::string& func_name) {
    emit(".globl " + func_name);
    emit(func_name + ":");
    emit("  pushq %rbp");
    emit("  movq %rsp, %rbp");
}

void AssemblyGenerator::emit_function_epilogue() {
    emit("  popq %rbp");
    emit("  ret");
}

std::string AssemblyGenerator::allocate_register(const std::string& temp) {
    if (available_registers.empty()) return "rax"; // fallback
    std::string reg = available_registers.back();
    available_registers.pop_back();
    register_map[temp] = reg;
    return reg;
}

void AssemblyGenerator::free_register(const std::string& temp) {
    if (register_map.count(temp)) {
        available_registers.push_back(register_map[temp]);
        register_map.erase(temp);
    }
}

void AssemblyGenerator::generate_from_ir(const std::vector<IRInstruction>& instructions) {
    for (const auto& instr : instructions) {
        switch (instr.op) {
            case OpCode::FUNCTION_BEGIN:
                emit_function_prologue(instr.arg1);
                break;
            case OpCode::RETURN:
                emit("  movq " + instr.arg1 + ", %rax");
                emit_function_epilogue();
                break;
            case OpCode::FUNCTION_END:
                break;
            default:
                emit("  # Unsupported op " + std::to_string((int)instr.op));
        }
    }

    output_file.close();
}
