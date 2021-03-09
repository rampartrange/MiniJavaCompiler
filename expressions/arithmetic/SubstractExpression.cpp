#include "SubstractExpression.h"

SubstractExpression::SubstractExpression(Expression* lhs, Expression* rhs, const location_type& loc):
    BinaryExpression(lhs, rhs, loc, "SubExpression") {}

void SubstractExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
