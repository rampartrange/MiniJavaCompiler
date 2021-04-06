#pragma once
#include <statements/Declaration.h>
#include <statements/Statement.h>
#include <vector>

class DeclarationList : public Statement {
public:
    DeclarationList(const location_type& loc);

    void AddDeclaration(Declaration* assignment);

    void Accept(Visitor* visitor) override;

    std::vector<Declaration*> declarations_;
};
