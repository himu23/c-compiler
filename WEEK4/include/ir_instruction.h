#ifndef IR_INSTRUCTION_H
#define IR_INSTRUCTION_H

#include <string>

enum class OpCode {
    ADD, SUB, MUL, DIV, MOD,
    EQ, NE, LT, LE, GT, GE,
    AND, OR, NOT,
    ASSIGN, COPY,
    GOTO, IF_FALSE, IF_TRUE,
    PARAM, CALL, RETURN,
    ARRAY_ACCESS, ARRAY_ASSIGN,
    LABEL, FUNCTION_BEGIN, FUNCTION_END
};

class IRInstruction {
public:
    OpCode op;
    std::string result;
    std::string arg1;
    std::string arg2;

    IRInstruction(OpCode op, std::string result = "", std::string arg1 = "", std::string arg2 = "")
        : op(op), result(std::move(result)), arg1(std::move(arg1)), arg2(std::move(arg2)) {}

    std::string to_string() const;
};

#endif
