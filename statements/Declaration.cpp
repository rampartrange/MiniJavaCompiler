#include "Declaration.h"

Declaration::Declaration(std::string  variable,
                         std::string type, const location_type &loc) :
    Statement(loc, "Declaration"),
    variable_(std::move(variable)),
    type_(std::move(type)) {}

void Declaration::Accept(Visitor* visitor) {
    visitor->Visit(this);
}