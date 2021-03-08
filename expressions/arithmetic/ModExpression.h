#pragma once
#include "expressions/BinaryExpression.h"

class ModExpression: public BinaryExpression {
public:
    ModExpression(Expression* lhs, Expression* rhs, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
};
