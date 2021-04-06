#pragma once

#include "visitor.h"

#include <fstream>
#include <string>

class PrintVisitor: public Visitor {
 public:
    PrintVisitor(const std::string& filename);
    ~PrintVisitor();
    virtual void Visit(AddExpression* expression) override;
    virtual void Visit(AndExpression* expression) override;
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

    virtual void Visit(Assignment* assignment) override;
    virtual void Visit(AssignmentList* assignmentList) override;
    virtual void Visit(Declaration* declaration) override;
    virtual void Visit(DeclarationList* declarationList) override;
    virtual void Visit(IfStatement* statement) override;
    virtual void Visit(WhileStatement* statement) override;
    virtual void Visit(StatementList* statementList) override;

    virtual void Visit(Program* program) override;

 private:

    void VisitBinaryExpression(BinaryExpression* exp);
    void VisitUnaryExpression(UnaryExpression *exp);

    void PrintTabs();

    void PrintObjectValue(BaseObject* object_ptr);
    std::ofstream stream_;
    int num_tabs_ = 0;
};
