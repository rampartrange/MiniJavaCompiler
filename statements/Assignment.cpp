#include "Assignment.h"

Assignment::Assignment(std::string  variable,
                       Expression* expression, const location_type &loc) :
        Statement(loc, "Assignment"),
        variable_(std::move(variable)),
        expression_(expression) {}

void Assignment::Accept(Visitor* visitor) {
    visitor->Visit(this);
}