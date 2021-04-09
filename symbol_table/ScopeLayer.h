#pragma once
#include "Symbol.h"
#include "objects/BaseObject.h"

#include <unordered_map>
#include <string>
#include <memory>
#include <vector>


class ScopeLayer {
 public:
    explicit ScopeLayer(ScopeLayer* parent);
    ScopeLayer();
    void DeclareVariable(Symbol symbol);
    void Put(Symbol symbol, BaseObject* value);
    BaseObject* Get(Symbol symbol);
    bool Has(Symbol symbol);

    void AddChild(ScopeLayer* child);
    void AttachParent();

    ScopeLayer* GetChild(size_t index);
    ScopeLayer* GetParent() const;
 private:
    std::unordered_map<Symbol, BaseObject*> values_;
    std::unordered_map<Symbol, size_t> offsets_;
    std::vector<Symbol> symbols_;
    std::string name_;
    ScopeLayer* parent_;
    std::vector<ScopeLayer*> children_;
};
