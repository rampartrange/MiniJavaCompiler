#include "MulExpression.h"

MulExpression::MulExpression(Expression *lhs, Expression *rhs
, const location_type &loc): Expression(loc),lhs(lhs), rhs(rhs) {}

PascalObject MulExpression::eval() const {
    return lhs->eval() * rhs->eval();
}

void MulExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
