#pragma once
#include "expressions/BinaryExpression.h"

class AddExpression: public BinaryExpression {
  public:
    AddExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
};
