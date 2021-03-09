#include "BooleanExpression.h"

BooleanExpression::BooleanExpression(bool value, const location_type& loc) :
    Expression(loc, "BooleanExpression"),
    object(value) {}

void BooleanExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

bool BooleanExpression::GetValue() const {
    return object.GetValue();
}