#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"

class SubstractExpression: public Expression {
 public:
    SubstractExpression(Expression* e1, Expression* e2, const location_type &loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* lhs;
    Expression* rhs;
    location_type location;
};

