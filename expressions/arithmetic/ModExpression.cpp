#include "ModExpression.h"

ModExpression::ModExpression(Expression* lhs, Expression* rhs
, const location_type &loc): BinaryExpression(lhs, rhs, loc, "ModExpression") {}

void ModExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
