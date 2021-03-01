#pragma once
#include "Expression.h"
#include "../objects/PascalObject.h"

class NotExpression: public Expression {
public:
    NotExpression(Expression* lhs);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;
//    const location_type& GetLocation() const override;


    Expression* lhs;
//    location_type location;
};
