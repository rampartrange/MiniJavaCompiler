#include "symboltreevisitor.h"

#include "elements.h"
#include <iostream>


///______________________Constructor/Destructor_______________________________///
SymbolTreeVisitor::SymbolTreeVisitor() :
    tree_(new ScopeLayer) {
    tree_.root_->DeclareVariable(Symbol("one"));
    tree_.root_->DeclareVariable(Symbol("two"));
    current_layer_ = tree_.root_;
}
///________________________Helper_____________________________________________///

ScopeLayer* SymbolTreeVisitor::GetRoot() {
    return current_layer_;
}

///______________________VisitGeneralExpression_______________________________///

void SymbolTreeVisitor::VisitBinaryExpression(BinaryExpression* exp) {
    std::cout << "Hello";
}

void SymbolTreeVisitor::VisitUnaryExpression(UnaryExpression* exp) {
    std::cout << "BYE";
}

///___________________________Statement_______________________________________///

void SymbolTreeVisitor::Visit(Assignment* assignment) {
    std::cout << "Declared var: " << assignment->variable_ << '\n';
    tree_.root_->DeclareVariable(Symbol(assignment->variable_));
}

void SymbolTreeVisitor::Visit(AssignmentList* assignment_list) {

}

void SymbolTreeVisitor::Visit(Declaration* declaration) {

}

void SymbolTreeVisitor::Visit(DeclarationList* declarationList) {

}

void SymbolTreeVisitor::Visit(IfStatement* statement) {

}

void SymbolTreeVisitor::Visit(WhileStatement *statement) {

}

void SymbolTreeVisitor::Visit(StatementList* statementList) {
    for (Statement* assignment: statementList->statements_) {
        assignment->Accept(this);
    }
}
///___________________________Arithmetic_______________________________________///

void SymbolTreeVisitor::Visit(AddExpression* expression) {
    VisitBinaryExpression(expression);
}

void SymbolTreeVisitor::Visit(DivExpression* expression) {
    VisitBinaryExpression(expression);
}

void SymbolTreeVisitor::Visit(ModExpression* expression) {
    VisitBinaryExpression(expression);
}

void SymbolTreeVisitor::Visit(MulExpression* expression) {
    VisitBinaryExpression(expression);
}

void SymbolTreeVisitor::Visit(SubstractExpression* expression) {
    VisitBinaryExpression(expression);
}
void SymbolTreeVisitor::Visit(UnaryMinusExpression* expression) {
    VisitUnaryExpression(expression);
}

///________________________logic_________________________________///

void SymbolTreeVisitor::Visit(AndExpression* expression) {
    VisitBinaryExpression(expression);
}


void SymbolTreeVisitor::Visit(ComparisonExpression* expression) {

}

void SymbolTreeVisitor::Visit(NotExpression* expression) {
    VisitUnaryExpression(expression);
}

void SymbolTreeVisitor::Visit(OrExpression* expression) {
    VisitBinaryExpression(expression);
}

void SymbolTreeVisitor::Visit(XorExpression* expression) {
    VisitBinaryExpression(expression);
}


///__________________________Object_______________________________________///

void SymbolTreeVisitor::Visit(IdentExpression* expression) {

}

void SymbolTreeVisitor::Visit(ObjectExpression* expression) {

}



///______________________________Program___________________________///
void SymbolTreeVisitor::Visit(Program* program) {
    program->statementList_->Accept(this);
    //program->expression_->Accept(this); // tos value is called
}

