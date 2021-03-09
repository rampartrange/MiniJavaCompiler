#include "BooleanObject.h"

BooleanObject::BooleanObject() : BaseObject(SimpleType::BOOLEAN) {}

BooleanObject::BooleanObject(bool value) : BaseObject(SimpleType::BOOLEAN), value(value) {}

bool BooleanObject::GetValue() const {
    return value;
}