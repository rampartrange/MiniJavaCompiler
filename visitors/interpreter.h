#pragma once

#include "visitor.h"
#include "elements.h"
#include <map>
#include <variant>
#include <iostream>

class Interpreter : public Visitor {
  public:

    Interpreter();
    ~Interpreter();

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

    const std::map<std::string, BasicTypes>& GetResult(Program* program);
 private:
    template <typename T>
    std::pair<T, T> VisitBinaryExpression(BinaryExpression* exp);

    std::map<std::string, BasicTypes> variables_;
    bool is_tos_expression_;
    BasicTypes tos_value_;

    void SetTosValue(BasicTypes value);
    void UnsetTosValue();
    bool CalculateComparison(const BasicTypes& lhs, const BasicTypes& rhs, ComparisonType type, BinaryExpression* expression);
    template <typename T>
    bool CompareTwoElements(const BasicTypes& lhs, const BasicTypes& rhs, ComparisonType type, BinaryExpression* expression);

    //int GetInt(BasicTypes object);
};