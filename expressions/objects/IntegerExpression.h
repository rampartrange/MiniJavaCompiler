#pragma once

#include "../Expression.h"
#include "../../objects/IntegerObject.h"

class IntegerExpression : public Expression {
public:
    IntegerExpression(int value, const location_type& loc);

    void Accept(Visitor* visitor) override;

    int GetValue() const;

private:
    IntegerObject object;
};
