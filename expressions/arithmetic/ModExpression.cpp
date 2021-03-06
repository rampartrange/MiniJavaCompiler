#include "ModExpression.h"

ModExpression::ModExpression(Expression *lhs, Expression *rhs
, const location_type &loc): Expression(loc), lhs(lhs), rhs(rhs) {}

PascalObject ModExpression::eval() const {
    return lhs->eval() % rhs->eval();
}

void ModExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
