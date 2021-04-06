#include "AssignmentList.h"

AssignmentList::AssignmentList(const location_type &loc) : Statement(loc, "AssignmentList"){}

void AssignmentList::AddAssignment(Assignment* assignment) {
    assignments_.push_back(assignment);
}

void AssignmentList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
