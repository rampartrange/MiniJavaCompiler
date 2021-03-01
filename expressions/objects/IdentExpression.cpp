#include "IdentExpression.h"

#include <utility>

IdentExpression::IdentExpression(std::string  ident, PascalObject value): ident_(std::move(ident)), value_(value) {}

PascalObject IdentExpression::eval() const {
    return value_;
}

void IdentExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

//const location_type& IdentExpression::GetLocation() const {
//    return location;
//}