#include "OrExpression.h"

OrExpression::OrExpression(Expression *lhs, Expression *rhs, const location_type &loc): Expression(loc), lhs(lhs), rhs(rhs) {}

PascalObject OrExpression::eval() const {
    return PascalObject(static_cast<bool>((lhs->eval()) || (rhs->eval())));
}

void OrExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
