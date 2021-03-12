#ifndef INTERPRETER_H
#define INTERPRETER_H

#include "visitor.h"
#include <map>
#include <variant>

class Interpreter : public Visitor {
  public:

    using BasicTypes = std::variant<int, bool, std::string>;

    Interpreter();
    ~Interpreter();
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

    int GetResult(Program* program);
 private:

    virtual void VisitBinaryExpression(BinaryExpression* exp) override;
    virtual void VisitUnaryExpression(UnaryExpression *exp) override;

    std::map<std::string, BasicTypes> variables_;
    bool is_tos_expression_;
    BasicTypes tos_value_;

    void SetTosValue(BasicTypes value);
    void UnsetTosValue();

    int GetInt(BasicTypes object);

    void ExitWithError(const std::string& message);
};

#endif // INTERPRETER_H
