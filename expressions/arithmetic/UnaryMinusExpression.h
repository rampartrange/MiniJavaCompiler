#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"

class UnaryMinusExpression: virtual public Expression {
public:
    UnaryMinusExpression(Expression* lhs, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;


    Expression* lhs;
    int value;
};
