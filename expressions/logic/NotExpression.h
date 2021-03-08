#pragma once
#include "expressions/UnaryExpression.h"

class NotExpression: public UnaryExpression {
public:
    NotExpression(Expression* exp, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
};
