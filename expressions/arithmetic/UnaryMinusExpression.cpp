#include "UnaryMinusExpression.h"


UnaryMinusExpression::UnaryMinusExpression(Expression* exp, const location_type &loc) :
    UnaryExpression(exp, loc, "UnaryMinusExpression") {}

PascalObject UnaryMinusExpression::eval() const{
    return -exp->eval();
}

void UnaryMinusExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
