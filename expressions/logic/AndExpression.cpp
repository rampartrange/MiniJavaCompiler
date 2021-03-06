#include "AndExpression.h"

AndExpression::AndExpression(Expression *lhs, Expression *rhs
, const location_type &loc): Expression(loc), lhs(lhs), rhs(rhs) {}

PascalObject AndExpression::eval() const {
    return PascalObject(static_cast<bool>(lhs->eval() && rhs->eval()));
}

void AndExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
