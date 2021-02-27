#pragma once

#include "visitors/visitor.h"


class BaseElement {
 public:
    virtual void Accept(Visitor* visitor) = 0;
    virtual ~BaseElement() = default;
}; 
