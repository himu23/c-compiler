#include "ir_instruction.h"

std::string IRInstruction::to_string() const {
    switch (op) {
        case OpCode::ASSIGN: return result + " = " + arg1;
        case OpCode::COPY:   return result + " := " + arg1;
        case OpCode::ADD:    return result + " = " + arg1 + " + " + arg2;
        case OpCode::SUB:    return result + " = " + arg1 + " - " + arg2;
        case OpCode::MUL:    return result + " = " + arg1 + " * " + arg2;
        case OpCode::DIV:    return result + " = " + arg1 + " / " + arg2;
        case OpCode::MOD:    return result + " = " + arg1 + " % " + arg2;
        case OpCode::EQ:     return result + " = " + arg1 + " == " + arg2;
        case OpCode::NE:     return result + " = " + arg1 + " != " + arg2;
        case OpCode::LT:     return result + " = " + arg1 + " < " + arg2;
        case OpCode::LE:     return result + " = " + arg1 + " <= " + arg2;
        case OpCode::GT:     return result + " = " + arg1 + " > " + arg2;
        case OpCode::GE:     return result + " = " + arg1 + " >= " + arg2;
        case OpCode::AND:    return result + " = " + arg1 + " && " + arg2;
        case OpCode::OR:     return result + " = " + arg1 + " || " + arg2;
        case OpCode::NOT:    return result + " = !" + arg1;
        case OpCode::GOTO:   return "goto " + arg1;
        case OpCode::IF_FALSE: return "ifFalse " + arg1 + " goto " + result;
        case OpCode::IF_TRUE:  return "if " + arg1 + " goto " + result;
        case OpCode::PARAM:  return "param " + arg1;
        case OpCode::CALL:   return result + " = call " + arg1 + ", " + arg2;
        case OpCode::RETURN: return "return " + arg1;
        case OpCode::ARRAY_ACCESS: return result + " = " + arg1 + "[" + arg2 + "]";
        case OpCode::ARRAY_ASSIGN: return arg1 + "[" + arg2 + "] = " + result;
        case OpCode::LABEL:  return arg1 + ":";
        case OpCode::FUNCTION_BEGIN: return "func " + arg1 + " {";
        case OpCode::FUNCTION_END:   return "}";
        default: return "// unknown";
    }
}
