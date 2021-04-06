#pragma once
#include <statements/Statement.h>
#include <expressions/Expression.h>

class IfStatement : public Statement {
public:
    IfStatement(Expression* expression,
                Statement* statement,
                const location_type& loc);

    IfStatement(Expression* expression,
                Statement* statement,
                Statement* elseStatement,
                const location_type& loc);

    void Accept(Visitor* visitor);

    Expression* expression_;
    Statement* statement_;
    Statement* elseStatement_{nullptr};

};

