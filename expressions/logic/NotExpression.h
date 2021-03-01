#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"

class NotExpression: virtual public Expression {
public:
    NotExpression(Expression* lhs, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* lhs;
};
