#pragma once
#include <statements/Statement.h>
#include <expressions/Expression.h>

class WhileStatement : public Statement {
public:
    WhileStatement(Expression* expression,
                Statement* statement,
                const location_type& loc);

    void Accept(Visitor* visitor);

    Expression* expression_;
    Statement* statement_;
};
