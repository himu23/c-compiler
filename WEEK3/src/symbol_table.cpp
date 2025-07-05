#include "../include/symbol_table.h"

SymbolTable::SymbolTable(SymbolTable* p)
    : parent(p), current_scope((p ? p->current_scope + 1 : 0)) {}

void SymbolTable::enter_scope() {
    children.push_back(std::make_unique<SymbolTable>(this));
}

void SymbolTable::exit_scope() {
    // do nothing now
}

bool SymbolTable::declare_symbol(std::unique_ptr<Symbol> symbol) {
    const std::string& name = symbol->name;
    if (symbols.count(name)) return false; // duplicate
    symbols[name] = std::move(symbol);
    return true;
}

Symbol* SymbolTable::lookup_current_scope(const std::string& name) {
    if (symbols.count(name)) return symbols[name].get();
    return nullptr;
}

Symbol* SymbolTable::lookup_symbol(const std::string& name) {
    SymbolTable* current = this;
    while (current) {
        if (current->symbols.count(name))
            return current->symbols[name].get();
        current = current->parent;
    }
    return nullptr;
}
