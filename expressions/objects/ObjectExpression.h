#pragma once

#include "../Expression.h"

class ObjectExpression: virtual public Expression {
public:
    explicit ObjectExpression(int value, const location_type& loc);
    explicit ObjectExpression(double value, const location_type& loc);
    explicit ObjectExpression(std::string value, const location_type& loc);
    explicit ObjectExpression(bool value, const location_type& loc);

    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    PascalObject value;
};

