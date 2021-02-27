#pragma once

#include "BaseObject.h"

class IntegerObject : BaseObject {
public:
    IntegerObject();
    explicit IntegerObject(int);

    void Accept() override;

    SimpleType GetType() const override;

private:
    int value_;

};



