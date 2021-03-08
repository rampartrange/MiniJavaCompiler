#pragma once
#include "expressions/BinaryExpression.h"

class XorExpression: public BinaryExpression {
public:
    XorExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
};
