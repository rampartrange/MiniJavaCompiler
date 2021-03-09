#pragma once

#include "BaseObject.h"

class IntegerObject : public BaseObject {
public:
    IntegerObject();
    explicit IntegerObject(int);

    int GetValue() const;

private:
    int value{0};
};



