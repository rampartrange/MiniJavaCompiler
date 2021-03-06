#pragma once

#include "BaseObject.h"

class DoubleObject : public BaseObject {
public:
    DoubleObject();
    explicit DoubleObject(double);

    void Accept() override;

    SimpleType GetType() const override;

private:
    double value_;
};



