#pragma once
#include "../Expression.h"
#include "../../objects/BooleanObject.h"

class BooleanExpression : public Expression {
public:
    BooleanExpression(bool value, const location_type& loc);

    void Accept(Visitor* visitor) override ;

    bool GetValue() const;

private:
    BooleanObject object;
};

