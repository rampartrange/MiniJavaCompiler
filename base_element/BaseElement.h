#pragma once

#include "visitors/visitor.h"
#include "parser.hh"

using location_type = yy::parser::location_type;

class BaseElement {
 public:
    BaseElement() = default;
    BaseElement(const location_type& location) : location(location) {}

    virtual void Accept(Visitor* visitor) = 0;

    const location_type& GetLocation() const {
        return location;
    }

    virtual ~BaseElement() = default;

    location_type location;
}; 
