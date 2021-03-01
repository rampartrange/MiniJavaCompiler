#include "UnaryMinusExpression.h"


UnaryMinusExpression::UnaryMinusExpression(Expression *lhs, const location_type &loc) : BaseElement(loc), lhs(lhs) {}

PascalObject UnaryMinusExpression::eval() const{
    return -lhs->eval();
}

void UnaryMinusExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
