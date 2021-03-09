#include "StringExpression.h"

StringExpression::StringExpression(std::string value, const location_type& loc) :
    Expression(loc, "StringExpression"),
    object(std::move(value)) {}

void StringExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

const std::string& StringExpression::GetValue() const {
    return object.GetValue();
}