#pragma once
#include "forward_decl.h"

#include <string>

class Visitor {
 public:
    virtual void Visit(Assignment* assignment) = 0;
    virtual void Visit(AssignmentList* assignment_list) = 0;

    virtual void Visit(AddExpression* expression) = 0;
    virtual void Visit(AndExpression* expression) = 0;
    virtual void Visit(AssignmentExpression* expression) = 0;
    virtual void Visit(ComparisonExpression* expression) = 0;
    virtual void Visit(DivExpression* expression) = 0;
    virtual void Visit(IdentExpression* expression) = 0;

    virtual void Visit(ModExpression* expression) = 0;
    virtual void Visit(MulExpression* expression) = 0;
    virtual void Visit(NotExpression* expression) = 0;
    virtual void Visit(ObjectExpression* expression) = 0;
    virtual void Visit(IntegerExpression* expression) = 0;
    virtual void Visit(BooleanExpression* expression) = 0;
    virtual void Visit(StringExpression* expression) = 0;
    virtual void Visit(OrExpression* expression) = 0;
    virtual void Visit(SubstractExpression* expression) = 0;
    virtual void Visit(UnaryMinusExpression* expression) = 0;
    virtual void Visit(XorExpression* expression) = 0;

    virtual void Visit(Program* expression) = 0;
    virtual void Visit(PascalObject* expression) = 0; //To remove


protected:
    virtual void VisitBinaryExpression(BinaryExpression* exp) = 0;
    virtual void VisitUnaryExpression(UnaryExpression* exp) = 0;
};
