#pragma once
#include "../objects/PascalObject.h"
#include "base_element/BaseElement.h"

class Expression : virtual public BaseElement {
public:
    virtual PascalObject eval() const = 0;
};


