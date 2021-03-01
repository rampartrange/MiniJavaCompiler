#pragma once
#include "Expression.h"
#include "../objects/PascalObject.h"

class OrExpression: public Expression {
public:
    OrExpression(Expression* lhs, Expression* rhs);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
//    const location_type& GetLocation() const override;


    Expression* lhs;
    Expression* rhs;
//    location_type location;
};
