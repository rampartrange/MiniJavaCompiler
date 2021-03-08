#include "NotExpression.h"

NotExpression::NotExpression(Expression* exp, const location_type &loc) :
    UnaryExpression(exp, loc, "NotExpression") {}

PascalObject NotExpression::eval() const {
    return PascalObject(static_cast<bool>(!(exp->eval())));
}

void NotExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
