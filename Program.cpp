#include "Program.h"

Program::Program(
    StatementList* statementList,
    Expression* expression
): statementList_(statementList), expression_(expression) {}