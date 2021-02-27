#pragma once

#include "JavaObject.h"

class Integer : JavaObject {
public:
    Integer();
    explicit Integer(int);

    //void Accept() override {};

    SimpleType GetType() const override;

private:
    int value_;

};



