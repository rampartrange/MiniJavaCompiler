#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"

class OrExpression: public Expression {
public:
    OrExpression(Expression* lhs, Expression* rhs);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;


    Expression* lhs;
    Expression* rhs;
};
