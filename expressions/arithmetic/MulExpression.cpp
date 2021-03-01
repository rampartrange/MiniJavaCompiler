#include "MulExpression.h"

MulExpression::MulExpression(
    Expression *lhs, Expression *rhs
): lhs(lhs), rhs(rhs) {}

PascalObject MulExpression::eval() const {
    return lhs->eval() * rhs->eval();
}

void MulExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

//const location_type& MulExpression::GetLocation() const {
//    return location;
//}