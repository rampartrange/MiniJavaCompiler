#pragma once

#include <string>
#include "BaseObject.h"

class StringObject : BaseObject {
public:
    StringObject();
    explicit StringObject(std::string);
    const std::string& GetValue() const;

private:
    std::string value{};
};

