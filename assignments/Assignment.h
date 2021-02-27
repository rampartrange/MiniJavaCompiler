#pragma once

#include "expressions/Expression.h"
#include "base_element/BaseElement.h"
#include <string>

class Assignment : BaseElement {
 public:
    Assignment(const std::string& variable, Expression* expression);
 private:
    std::string variable_;
    Expression* expression_;
};
