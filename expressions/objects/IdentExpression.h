#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"
#include <string>

class IdentExpression: public Expression {
 public:
    IdentExpression(std::string  ident, PascalObject value, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;

    std::string ident_;
    PascalObject value_;
};
