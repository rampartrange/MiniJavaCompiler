#include "printvisitor.h"

#include "elements.h"
#include <iostream>


///______________________Constructor/Destructor_______________________________///

SymbolTreeVisitor::SymbolTreeVisitor(const std::string& filename) :
    stream_(filename) {}

SymbolTreeVisitor::~SymbolTreeVisitor() {
    stream_.close();
}

///________________________Helper_____________________________________________///

void SymbolTreeVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}

///______________________VisitGeneralExpression_______________________________///

void SymbolTreeVisitor::VisitBinaryExpression(BinaryExpression* exp) {
    PrintTabs();
    stream_ << exp->GetName() << " (loc): " << exp->GetLocation() << ' '  << std::endl;

    ++num_tabs_;
    exp->lhs->Accept(this);
    exp->rhs->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::VisitUnaryExpression(UnaryExpression* exp) {
    PrintTabs();

    stream_ << exp->GetName() << " (loc): " << exp->GetLocation() << ' '  << std::endl;
    ++num_tabs_;
    exp->exp->Accept(this);
    --num_tabs_;
}

///___________________________Assignment_______________________________________///

void SymbolTreeVisitor::SymbolTreeVisitor::Visit(Assignment* assignment) {
    PrintTabs();
    stream_ << "Assignment:  (loc): " << assignment->GetLocation() << " (var name): "
             << assignment->variable_ << std::endl;
    ++num_tabs_;
    assignment->expression_->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(AssignmentList* assignment_list) {
    PrintTabs();
    stream_ << "AssignmentList (loc): " << assignment_list->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    for (Assignment* assignment : assignment_list->assignments_) {
        assignment->Accept(this);
    }
    --num_tabs_;
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
    PrintTabs();
    stream_ << "ComparisonExpression (loc): " << expression->GetLocation() << ' '  <<  std::endl;

    ++num_tabs_;
    expression->lhs->Accept(this);
    stream_ << ComparisonTypeToString[(int)expression->type] << std::endl;
    expression->rhs->Accept(this);
    expression->value.Accept(this);
    --num_tabs_;
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

void SymbolTreeVisitor::Visit(PascalObject* expression) {
    PrintTabs();
    stream_ << "Pascal object (loc): " << expression->GetLocation() << ' '  << std::endl;

    ++num_tabs_;

    PrintTabs();
    stream_ << expression->GetIntValue() << std::endl; //!!!!

    --num_tabs_;
}

void SymbolTreeVisitor::Visit(AssignmentExpression* expression) {
    PrintTabs();
    stream_ << "Assignment expression (loc): " << expression->GetLocation() << ' '  << expression->variable_ << std::endl;

    ++num_tabs_;
    expression->expression_->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(IdentExpression* expression) {
    PrintTabs();
    stream_ << "IdentExpression (loc): " << expression->GetLocation() << ' '  <<  expression->ident_ << std::endl;
}

void SymbolTreeVisitor::Visit(ObjectExpression* expression) {
    PrintTabs();
    stream_ << "ObjectExpression (loc): " << expression->GetLocation() << ' '  << std::endl;
    ++num_tabs_;
    expression->value.Accept(this);
    --num_tabs_;
}


///______________________________Program___________________________///
void SymbolTreeVisitor::Visit(Program* program) {
    stream_ << "Program (loc): " << std::endl;

    ++num_tabs_;

    program->assignments_->Accept(this);
    if (program->expression_ != nullptr)
        program->expression_->Accept(this);

    --num_tabs_;
}
