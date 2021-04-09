#include "Table.h"

#include <utility>
#include <iostream>

Table::Table() {}

void Table::Put(Symbol symbol, BaseObject* value) {
    std::cout << "Put " << symbol.GetName() << " value " << value->GetName() << std::endl;
    if (values_.find(symbol) == values_.end()) {
        throw std::runtime_error(symbol.GetName() +  ": variable not declared");
    }
    values_[symbol].pop();
    values_[symbol].push(value);
    symbols_.push(symbol);
}

BaseObject* Table::Get(Symbol symbol) {
    if (values_.find(symbol) == values_.end()) {
        throw std::runtime_error(symbol.GetName() + ": variable not declared");
    }
    return values_[symbol].top();
}

void Table::CreateVariable(Symbol symbol) {
    std::cerr << "Creating variable " << symbol.GetName() << std::endl;
    if (values_.find(symbol) == values_.end()) {
        values_[symbol] = std::stack<BaseObject*>();
    }
    values_[symbol].push(nullptr); //Заглушка
}

void Table::BeginScope() {
    symbols_.push(Symbol("{"));
}

void Table::EndScope() {
    while (symbols_.top() != Symbol("{")) {
        Symbol symbol = symbols_.top();

        std::cerr << "Popping " << symbol.GetName() << std::endl;

        values_[symbol].pop();
        if (values_[symbol].empty()) {
            values_.erase(symbol);
        }
        symbols_.pop();
    }
    symbols_.pop();
}

Symbol Table::GetSymbol(const std::string& name) {
    auto it = symbols_map_.find(name);
    if (it == symbols_map_.end()) {
        Symbol symbol(name);
        symbols_map_.insert({name, symbol});
        return symbol;
    } else {
        return it->second;
    }
}
