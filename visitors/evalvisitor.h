#pragma once

#include "visitor.h"
#include <string>

class EvalTreeVisitor: public Visitor {
 public:
    EvalTreeVisitor(const std::string& filename);
    ~EvalTreeVisitor();
    void Visit(NumberExpression* expression) override;
    void Visit(AddExpression* expression) override;
    void Visit(SubstractExpression* expression) override;
    void Visit(MulExpression* expression) override;
    void Visit(DivExpression* expression) override;
    void Visit(IdentExpression* expression) override;
    void Visit(Assignment* assignment) override;
    void Visit(AssignmentList* assignment_list) override;
    void Visit(Program* program) override;
 private:
};
