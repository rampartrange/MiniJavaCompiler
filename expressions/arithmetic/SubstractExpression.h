#pragma once
#include "expressions/BinaryExpression.h"

class SubstractExpression: public BinaryExpression {
 public:
    SubstractExpression(Expression* lhs, Expression* rhs, const location_type &loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
};

