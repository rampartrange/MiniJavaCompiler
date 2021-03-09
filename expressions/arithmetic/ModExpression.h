#pragma once
#include "expressions/BinaryExpression.h"

class ModExpression: public BinaryExpression {
public:
    ModExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    void Accept(Visitor* visitor) override;
};
