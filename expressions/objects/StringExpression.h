#pragma once

#include "../Expression.h"
#include "../../objects/StringObject.h"

class StringExpression : public Expression {
public:
    StringExpression(std::string value, const location_type& loc);

    void Accept(Visitor* visitor) override;

    const std::string& GetValue() const;

private:
    StringObject object;
};