#pragma once

#include <string>
#include <vector>

#include "BaseObject.h"

class UserClassObject : virtual public BaseObject {
public:
    UserClassObject();

private:
    //std::vector<Method> methods_;
    std::vector<BaseObject*> fields_
    std::string name_;
};

