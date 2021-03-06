#include "StringObject.h"

#include <utility>

StringObject::StringObject() : value_() {}

StringObject::StringObject(std::string value) : value_(std::move(value)) {}

void StringObject::Accept() {}

SimpleType StringObject::GetType() const {
    return SimpleType::STRING;
}