#include "SubstractExpression.h"

SubstractExpression::SubstractExpression(Expression *e1, Expression *e2): lhs(e1), rhs(e2) {}

PascalObject SubstractExpression::eval() const {
    return lhs->eval() - rhs->eval();
}

void SubstractExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

//const location_type& SubstractExpression::GetLocation() const {
//    return location;
//}