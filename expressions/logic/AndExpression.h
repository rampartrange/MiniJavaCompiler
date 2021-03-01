#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"

class AndExpression: public Expression {
  public:
    AndExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* lhs;
    Expression* rhs;

};
