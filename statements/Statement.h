#pragma once
#include "base_element/BaseElement.h"

class Statement : public BaseElement {
public:
    Statement(const location_type& loc, const std::string& name) : BaseElement(loc, name) {};
    virtual ~Statement() = default;
};
