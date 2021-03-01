#pragma once
#include "Expression.h"
#include "../objects/PascalObject.h"

class SubstractExpression: public Expression {
 public:
    SubstractExpression(Expression* e1, Expression* e2);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
//    const location_type& GetLocation() const override;


    Expression* lhs;
    Expression* rhs;
    location_type location;
};

