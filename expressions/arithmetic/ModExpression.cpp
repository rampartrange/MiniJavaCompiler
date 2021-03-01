#include "ModExpression.h"

ModExpression::ModExpression(
        Expression *lhs, Expression *rhs
): lhs(lhs), rhs(rhs) {}

PascalObject ModExpression::eval() const {
    return lhs->eval() % rhs->eval();
}

void ModExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

//const location_type& ModExpression::GetLocation() const {
//    return location;
//}