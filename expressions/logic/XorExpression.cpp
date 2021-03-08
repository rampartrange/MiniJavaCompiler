#include "XorExpression.h"

XorExpression::XorExpression(Expression* lhs, Expression* rhs, const location_type &loc):
    BinaryExpression(lhs, rhs, loc, "XorExpression") {}

PascalObject XorExpression::eval() const {
    return PascalObject(static_cast<bool>(static_cast<bool>(lhs->eval()) ^ static_cast<bool>(rhs->eval())));
}

void XorExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
