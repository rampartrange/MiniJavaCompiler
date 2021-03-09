#include "IntegerObject.h"

IntegerObject::IntegerObject() : BaseObject(SimpleType::INT) {}

IntegerObject::IntegerObject(int value) : BaseObject(SimpleType::INT), value(value) {}

int IntegerObject::GetValue() const {
    return value;
}

