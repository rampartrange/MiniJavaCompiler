#pragma once

#include "visitors/elements.h"
#include "expressions/Expression.h"
#include "driver.hh"

class Program {
 public:
    Program(StatementList* statementList, Expression* expression);

    StatementList* statementList_;
    Expression* expression_;
};
