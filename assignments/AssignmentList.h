#pragma once

#include "assignments/Assignment.h"
#include "base_element/BaseElement.h"
#include <vector>

class AssignmentList : BaseElement {
 public:
    void AddAssignment(Assignment* assignment);
    void Accept(Visitor* visitor) override;

    std::vector<Assignment*> assignments_;
};
