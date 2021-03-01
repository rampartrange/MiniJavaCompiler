#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"

class UnaryMinusExpression: public Expression {
public:
    UnaryMinusExpression(Expression* lhs);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;


    Expression* lhs;
    int value;
};
