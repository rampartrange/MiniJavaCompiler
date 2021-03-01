#pragma once
#include "../objects/PascalObject.h"
#include "base_element/BaseElement.h"

class Expression : public BaseElement {
public:
    Expression(const location_type& loc) : BaseElement(loc) {};
    virtual PascalObject eval() const = 0;
    virtual ~Expression() = default;
};


