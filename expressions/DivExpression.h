#pragma once
#include "Expression.h"
#include "../objects/PascalObject.h"

class DivExpression: public Expression {
 public:
    DivExpression(Expression* e1, Expression* e2);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* lhs;
    Expression* rhs;
};
