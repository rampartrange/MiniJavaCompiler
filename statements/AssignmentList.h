#pragma once

#include "statements//Assignment.h"
#include "base_element/BaseElement.h"
#include <statements/Statement.h>
#include <vector>

class AssignmentList : public Statement {
 public:
    AssignmentList(const location_type& loc);
    void AddAssignment(Assignment* assignment);
    void Accept(Visitor* visitor) override;

    std::vector<Assignment*> assignments_;
};
