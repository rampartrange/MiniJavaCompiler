#include "AndExpression.h"

AndExpression::AndExpression(
        Expression *lhs, Expression *rhs
): lhs(lhs), rhs(rhs) {}

PascalObject AndExpression::eval() const {
    return PascalObject(static_cast<bool>(lhs->eval() && rhs->eval()));
}

void AndExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

//const location_type& AndExpression::GetLocation() const {
//    return location;
//}
