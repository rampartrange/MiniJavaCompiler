#include "SubstractExpression.h"

SubstractExpression::SubstractExpression(Expression* lhs, Expression* rhs, const location_type& loc):
    BinaryExpression(lhs, rhs, loc, "SubExpression") {}

PascalObject SubstractExpression::eval() const {
    return lhs->eval() - rhs->eval();
}

void SubstractExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
