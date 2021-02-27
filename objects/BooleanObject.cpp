#include "BooleanObject.h"

BooleanObject::BooleanObject() : value_(false) {};

BooleanObject::BooleanObject(bool value) : value_(value) {};

void BooleanObject::Accept() {}

SimpleType BooleanObject::GetType() const {
    return SimpleType::BOOLEAN;
}