#pragma once

#include "Symbol.h"
#include "objects/BaseObject.h"

#include <unordered_map>
#include <stack>

class Table {
 public:
    Table();

    void Put(Symbol symbol, BaseObject* value);

    void CreateVariable(Symbol symbol);

    Symbol GetSymbol(const std::string& name);

    BaseObject* Get(Symbol key);

    void BeginScope();
    void EndScope();
 private:
    std::unordered_map<Symbol, std::stack<BaseObject*>> values_;
    std::unordered_map<std::string, Symbol> symbols_map_;

    std::stack<Symbol> symbols_;

};
