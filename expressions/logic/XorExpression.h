#pragma once
#include "expressions/BinaryExpression.h"

class XorExpression: public BinaryExpression {
public:
    XorExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    void Accept(Visitor* visitor) override;
};
