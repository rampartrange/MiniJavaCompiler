#pragma once
#include "expressions/BinaryExpression.h"

class OrExpression: public BinaryExpression {
public:
    OrExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
};
