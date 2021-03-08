#include "ObjectExpression.h"

#include <utility>

ObjectExpression::ObjectExpression(int value, const location_type &loc) :
    Expression(loc, "ObjectExpression"),
    value(PascalObject(value)) {}

ObjectExpression::ObjectExpression(double value, const location_type &loc) :
    Expression(loc, "ObjectExpression"),
    value(PascalObject(value)) {}

ObjectExpression::ObjectExpression(std::string value, const location_type &loc) :
    Expression(loc, "ObjectExpression"),
    value(PascalObject(std::move(value))) {}

ObjectExpression::ObjectExpression(bool value, const location_type &loc) :
    Expression(loc, "ObjectExpression"), value(PascalObject(value)) {}

PascalObject ObjectExpression::eval() const {
    return value;
}

void ObjectExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
