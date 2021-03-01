#include "DivExpression.h"

DivExpression::DivExpression(
    Expression *e1, Expression *e2
): lhs(e1), rhs(e2) {}

PascalObject DivExpression::eval() const {
    return lhs->eval() / rhs->eval();
}

void DivExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}