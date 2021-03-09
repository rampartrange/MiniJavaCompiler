#pragma once

#include "../Expression.h"

class ObjectExpression: public Expression {
public:
    explicit ObjectExpression(int value, const location_type& loc);
    explicit ObjectExpression(double value, const location_type& loc);
    explicit ObjectExpression(std::string value, const location_type& loc);
    explicit ObjectExpression(bool value, const location_type& loc);

    void Accept(Visitor* visitor) override;

    PascalObject value;
};

