#pragma once

#include "assignments/Assignment.h"
#include "base_element/BaseElement.h"
#include <vector>

class AssignmentList : BaseElement {
 public:
    AssignmentList(const location_type& loc) : BaseElement(loc){};
    void AddAssignment(Assignment* assignment);
    void Accept(Visitor* visitor) override;

    std::vector<Assignment*> assignments_;
};
