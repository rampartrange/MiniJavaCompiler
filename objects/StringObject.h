#pragma once

#include <string>
#include "BaseObject.h"

class StringObject : BaseObject {
public:
    StringObject();
    explicit StringObject(std::string);

    void Accept() override;

    SimpleType GetType() const override;

private:
    std::string value_;
};

