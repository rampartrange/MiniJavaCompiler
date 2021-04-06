#include "DeclarationList.h"

DeclarationList::DeclarationList(const location_type &loc) : Statement(loc, "AssignmentList"){}

void DeclarationList::AddDeclaration(Declaration *declaration) {
    declarations_.push_back(declaration);
}

void DeclarationList::Accept(Visitor* visitor) {
    visitor->Visit(this);
}