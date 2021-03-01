#pragma once
#include "Expression.h"

class NumberExpression: public Expression {
public:
    explicit NumberExpression(int value);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    int value_;
};
