#pragma once
#include "Expression.h"
#include "../objects/PascalObject.h"

class UnaryMinusExpression: public Expression {
public:
    UnaryMinusExpression(Expression* lhs);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
//    const location_type& GetLocation() const override;


    Expression* lhs;
    int value;
//    location_type location;
};
