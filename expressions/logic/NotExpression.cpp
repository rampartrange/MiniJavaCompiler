#include "NotExpression.h"

NotExpression::NotExpression(Expression* lhs) : lhs(lhs) {}

PascalObject NotExpression::eval() const {
    return PascalObject(static_cast<bool>(!(lhs->eval())));
}

void NotExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}