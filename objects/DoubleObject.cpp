#include "DoubleObject.h"

DoubleObject::DoubleObject() : BaseObject(SimpleType::DOUBLE), value(0) {}

DoubleObject::DoubleObject(double value) : BaseObject(SimpleType::DOUBLE), value(value) {}

double DoubleObject::GetValue() const {
    return value;
}

