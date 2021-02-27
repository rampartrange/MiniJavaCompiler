#include "IntegerObject.h"

IntegerObject::IntegerObject() : value_(0) {};

IntegerObject::IntegerObject(int value) : value_(value) {};

void IntegerObject::Accept() {}

SimpleType IntegerObject::GetType() const {
    return SimpleType::INT;
}
