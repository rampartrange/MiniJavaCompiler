#pragma once
#include <statements/Statement.h>
#include <expressions/Expression.h>
#include <string>

class Assignment : public Statement {
public:
    Assignment(std::string  variable,
               Expression* expression, const location_type &loc);
    void Accept(Visitor* visitor);

    std::string variable_;
    Expression* expression_;
};

