#pragma once

#include "expressions/Expression.h"

#include <string>

class AssignmentExpression : public Expression {
 public:
    AssignmentExpression(std::string  variable, Expression* expression);
    void Accept(Visitor* visitor) override;
    //const location_type& GetLocation() const override;


    std::string variable_;
    Expression* expression_;
    //location_type location;
};
