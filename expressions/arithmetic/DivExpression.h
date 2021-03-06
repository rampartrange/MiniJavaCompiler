#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"

class DivExpression: virtual public Expression {
 public:
    DivExpression(Expression* e1, Expression* e2, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* lhs;
    Expression* rhs;
};
