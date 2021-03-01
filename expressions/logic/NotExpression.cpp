#include "NotExpression.h"

NotExpression::NotExpression(Expression* lhs) : lhs(lhs) {}

PascalObject NotExpression::eval() const {
    return PascalObject(static_cast<bool>(!(lhs->eval())));
}

void NotExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}

//const location_type& NotExpression::GetLocation() const {
//    return location;
//}