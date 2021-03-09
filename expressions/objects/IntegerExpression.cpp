#include "IntegerExpression.h"

IntegerExpression::IntegerExpression(int value, const location_type& loc) :
    Expression(loc, "IntegerExpression"),
    object(value) {}

void IntegerExpression::Accept(Visitor *visitor) {
    visitor->Visit(this);
}

int IntegerExpression::GetValue() const {
    return object.GetValue();
}