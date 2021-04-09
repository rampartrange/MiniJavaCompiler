#ifndef SYMBOLTREEVISITOR_H
#define SYMBOLTREEVISITOR_H

#include "visitor.h"
#include "symbol_table/ScopeLayerTree.h"
#include "symbol_table/Table.h"

class SymbolTreeVisitor: public Visitor {
 public:
    SymbolTreeVisitor();
    ~SymbolTreeVisitor() = default;

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

    ScopeLayer* GetRoot();

 private:

    void VisitBinaryExpression(BinaryExpression* exp);
    void VisitUnaryExpression(UnaryExpression *exp);

    ScopeLayerTree tree_;
    ScopeLayer* current_layer_;
};

#endif // SYMBOLTREEVISITOR_H
