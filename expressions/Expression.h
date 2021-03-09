#pragma once
#include "../objects/PascalObject.h"
#include "base_element/BaseElement.h"
#include "../objects/BaseObject.h"

class Expression : public BaseElement {
public:
    Expression(const location_type& loc, const std::string& name) : BaseElement(loc, name) {};
    virtual ~Expression() = default;
};


