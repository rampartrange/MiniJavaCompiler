#include "XorExpression.h"

XorExpression::XorExpression(Expression* lhs, Expression* rhs, const location_type &loc):
    BinaryExpression(lhs, rhs, loc, "XorExpression") {}

void XorExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
