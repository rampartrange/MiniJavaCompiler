#pragma once

#include "BaseObject.h"

class BooleanObject : public BaseObject {
public:
    BooleanObject();
    explicit BooleanObject(bool);

    void Accept() override;

    SimpleType GetType() const override;

private:
    bool value_;
};



