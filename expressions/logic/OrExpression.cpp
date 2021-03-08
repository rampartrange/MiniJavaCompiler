#include "OrExpression.h"

OrExpression::OrExpression(Expression* lhs, Expression* rhs, const location_type &loc):
    BinaryExpression(lhs, rhs, loc, "OrExpression") {}

PascalObject OrExpression::eval() const {
    return PascalObject(static_cast<bool>((lhs->eval()) || (rhs->eval())));
}

void OrExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
