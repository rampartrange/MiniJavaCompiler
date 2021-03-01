#pragma once
#include "../objects/PascalObject.h"
#include "base_element/BaseElement.h"

class Expression : public BaseElement {
public:
    virtual PascalObject eval() const = 0;
};
