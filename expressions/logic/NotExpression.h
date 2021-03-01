#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"

class NotExpression: public Expression {
public:
    NotExpression(Expression* lhs);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    Expression* lhs;
};
