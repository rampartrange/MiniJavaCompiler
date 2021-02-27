#include "DoubleObject.h"

DoubleObject::DoubleObject() : value_(0) {}

DoubleObject::DoubleObject(double value) : value_(value) {}

void DoubleObject::Accept() {}

SimpleType DoubleObject::GetType() const {
    return SimpleType::DOUBLE;
}

