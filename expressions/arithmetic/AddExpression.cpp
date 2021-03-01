#include "AddExpression.h"

AddExpression::AddExpression(Expression *lhs, Expression *rhs, const location_type& loc):
    BaseElement(loc),
    lhs(lhs),
    rhs(rhs) {}

PascalObject AddExpression::eval() const {
    return lhs->eval() + rhs->eval();
}

void AddExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
