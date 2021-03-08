#pragma once
#include "expressions/BinaryExpression.h"

class AndExpression: public BinaryExpression {
  public:
    AndExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
};
