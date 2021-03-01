#include "NotExpression.h"

NotExpression::NotExpression(Expression* lhs, const location_type &loc) :
    BaseElement(loc),
    lhs(lhs) {}

PascalObject NotExpression::eval() const {
    return PascalObject(static_cast<bool>(!(lhs->eval())));
}

void NotExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
