#include "IdentExpression.h"

#include <utility>

IdentExpression::IdentExpression(std::string  ident, PascalObject value, const location_type &loc):
    BaseElement(loc),
    ident_(std::move(ident)),
    value_(value) {}

PascalObject IdentExpression::eval() const {
    return value_;
}

void IdentExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
