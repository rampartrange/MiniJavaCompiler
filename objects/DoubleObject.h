#pragma once

#include "BaseObject.h"

class DoubleObject : public BaseObject {
public:
    DoubleObject();
    explicit DoubleObject(double);

    double GetValue() const;

private:
    double value;
};



