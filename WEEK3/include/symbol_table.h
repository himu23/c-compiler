#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <string>
#include <unordered_map>
#include <memory>
#include <vector>

enum class SymbolType { VARIABLE, FUNCTION };
enum class DataType { INT, VOID };

struct SourceLocation {
    int line;
    int column;
};

class Symbol {
public:
    std::string name;
    SymbolType symbol_type;
    int scope_level;
    SourceLocation location;

    virtual ~Symbol() = default;
};

class VariableSymbol : public Symbol {
public:
    DataType data_type;
    bool is_array = false;
    int array_size = 0;
    bool is_parameter = false;
};

class FunctionSymbol : public Symbol {
public:
    DataType return_type;
    std::vector<std::unique_ptr<VariableSymbol>> parameters;
    bool is_defined = false;
};

class SymbolTable {
    std::unordered_map<std::string, std::unique_ptr<Symbol>> symbols;
    SymbolTable* parent;
    std::vector<std::unique_ptr<SymbolTable>> children;
    int current_scope;

public:
    SymbolTable(SymbolTable* parent = nullptr);
    
    void enter_scope();
    void exit_scope();
    
    bool declare_symbol(std::unique_ptr<Symbol> symbol);
    Symbol* lookup_symbol(const std::string& name);
    Symbol* lookup_current_scope(const std::string& name);
};

#endif
