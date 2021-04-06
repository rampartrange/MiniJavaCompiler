#include "IfStatement.h"

IfStatement::IfStatement(Expression *expression,
                         Statement *statement,
                         const location_type &loc) :
                                Statement(loc, "IfStatement"),
                                expression_(expression),
                                statement_(statement) {}

IfStatement::IfStatement(Expression *expression,
                         Statement *statement,
                         Statement *elseStatement,
                         const location_type &loc) :
                                Statement(loc, "IfElseStatement"),
                                expression_(expression),
                                statement_(statement),
                                elseStatement_(elseStatement) {}

void IfStatement::Accept(Visitor *visitor) {
    visitor->Visit(this);
}