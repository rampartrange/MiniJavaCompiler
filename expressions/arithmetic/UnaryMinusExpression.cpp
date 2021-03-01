#include "UnaryMinusExpression.h"


UnaryMinusExpression::UnaryMinusExpression(Expression *lhs) : lhs(lhs) {}

PascalObject UnaryMinusExpression::eval() const{
    return -lhs->eval();
}

void UnaryMinusExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
