#pragma once

#include "visitor.h"

#include <fstream>
#include <string>

class SymbolTreeVisitor: public Visitor {
 public:
    SymbolTreeVisitor(const std::string& filename);
    ~SymbolTreeVisitor();
    virtual void Visit(Assignment* assignment) override;
    virtual void Visit(AssignmentList* expression) override;

    virtual void Visit(AddExpression* expression) override;
    virtual void Visit(AndExpression* expression) override;
    virtual void Visit(AssignmentExpression* expression) override;
    virtual void Visit(ComparisonExpression* expression) override;
    virtual void Visit(DivExpression* expression) override;
    virtual void Visit(IdentExpression* expression) override;
    virtual void Visit(ModExpression* expression) override;
    virtual void Visit(MulExpression* expression) override;
    virtual void Visit(NotExpression* expression) override;
    virtual void Visit(ObjectExpression* expression) override;
    virtual void Visit(OrExpression* expression) override;
    virtual void Visit(SubstractExpression* expression) override;
    virtual void Visit(UnaryMinusExpression* expression) override;
    virtual void Visit(XorExpression* expression) override;

    virtual void Visit(Program* program) override;

 private:

    virtual void VisitBinaryExpression(BinaryExpression* exp) override;
    virtual void VisitUnaryExpression(UnaryExpression *exp) override;

    void PrintTabs();

    void PrintObjectValue(BaseObject* object_ptr);
    std::ofstream stream_;
    int num_tabs_ = 0;
};
