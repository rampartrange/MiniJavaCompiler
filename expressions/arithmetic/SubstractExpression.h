#pragma once
#include "expressions/BinaryExpression.h"

class SubstractExpression: public BinaryExpression {
 public:
    SubstractExpression(Expression* lhs, Expression* rhs, const location_type &loc);
    void Accept(Visitor* visitor) override;
};

