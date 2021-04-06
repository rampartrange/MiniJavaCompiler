#include "WhileStatement.h"

WhileStatement::WhileStatement(Expression *expression,
                         Statement *statement,
                         const location_type &loc) :
    Statement(loc, "WhileStatement"),
    expression_(expression),
    statement_(statement) {}

void WhileStatement::Accept(Visitor *visitor) {
    visitor->Visit(this);
}