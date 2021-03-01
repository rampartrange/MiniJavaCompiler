#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"


class AddExpression: virtual public Expression {
  public:
    AddExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* lhs;
    Expression* rhs;
};
