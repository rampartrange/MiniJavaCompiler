#pragma once
#include "Expression.h"
#include "../objects/PascalObject.h"

class AddExpression: public Expression {
  public:
    AddExpression(Expression* lhs, Expression* rhs);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* lhs;
    Expression* rhs;
};
