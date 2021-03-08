#pragma once
#include "../objects/PascalObject.h"
#include "base_element/BaseElement.h"

class Expression : public BaseElement {
public:
    Expression(const location_type& loc, const std::string& name) : BaseElement(loc, name) {};
    virtual PascalObject eval() const = 0;
    virtual ~Expression() = default;
};


