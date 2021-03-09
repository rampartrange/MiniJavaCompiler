#pragma once

#include "BaseObject.h"

class BooleanObject : public BaseObject {
public:
    BooleanObject();
    explicit BooleanObject(bool);
    bool GetValue() const;

private:
    bool value{false};
};



