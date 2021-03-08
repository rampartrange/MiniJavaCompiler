#include "DivExpression.h"

DivExpression::DivExpression(Expression* lhs, Expression* rhs,
                             const location_type &loc) :
    BinaryExpression(lhs, rhs, loc, "DivExpression") {}

PascalObject DivExpression::eval() const {
    return lhs->eval() / rhs->eval();
}

void DivExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
