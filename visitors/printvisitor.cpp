#include "printvisitor.h"

#include "elements.h"
#include <iostream>

SymbolTreeVisitor::SymbolTreeVisitor(const std::string& filename) : stream_(filename) {}

void SymbolTreeVisitor::SymbolTreeVisitor::Visit(Assignment* assignment) {
    PrintTabs();
    stream_ << "Assignment:  (loc): " << assignment->GetLocation() << ' ' << assignment->variable_ << std::endl;
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

void SymbolTreeVisitor::Visit(AddExpression* expression) {
    PrintTabs();
    stream_ << "AddExpression (loc): " << expression->GetLocation() << ' '  << std::endl;

    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(AndExpression* expression) {
    PrintTabs();
    stream_ << "AndExpression (loc): " << expression->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(AssignmentExpression* expression) {
    PrintTabs();
    stream_ << "Assignment expression (loc): " << expression->GetLocation() << ' '  << expression->variable_ << std::endl;

    ++num_tabs_;
    expression->expression_->Accept(this);
    --num_tabs_;
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

void SymbolTreeVisitor::Visit(DivExpression* expression) {
    PrintTabs();
    stream_ << "DivExpression (loc): " << expression->GetLocation() << ' '  << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(IdentExpression* expression) {
    PrintTabs();

    stream_ << "IdentExpression (loc): " << expression->GetLocation() << ' '  <<  expression->ident_ << std::endl;
}
void SymbolTreeVisitor::Visit(ModExpression* expression) {
    PrintTabs();

    stream_ << "ModExpression: " << expression->GetLocation() << ' '  << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(MulExpression* expression) {
    PrintTabs();

    stream_ << "MulExpression (loc): " << expression->GetLocation() << ' '  << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(NotExpression* expression) {
    PrintTabs();

    stream_ << "NotExpression (loc): " << expression->GetLocation() << ' ' << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(ObjectExpression* expression) {
    PrintTabs();
    stream_ << "ObjectExpression (loc): " << expression->GetLocation() << ' '  << std::endl;
    ++num_tabs_;
    expression->value.Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(OrExpression* expression) {
    PrintTabs();

    stream_ << "OrExpression (loc): " << expression->GetLocation() << ' ' << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(SubstractExpression* expression) {
    PrintTabs();

    stream_ << "SubExpression (loc): " << expression->GetLocation() << ' ' << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(UnaryMinusExpression* expression) {
    PrintTabs();

    stream_ << "UnaryMinusExpression (loc): " << expression->GetLocation() << ' '  << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    stream_ << expression->value << std::endl;
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(XorExpression* expression) {
    PrintTabs();

    stream_ << "XorExpression (loc): " << expression->GetLocation() << ' ' << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(Program* program) {
    stream_ << "Program (loc): " << std::endl;

    ++num_tabs_;

    program->assignments_->Accept(this);
    if (program->expression_ != nullptr)
        program->expression_->Accept(this);

    --num_tabs_;
}

void SymbolTreeVisitor::Visit(PascalObject* expression) {
    PrintTabs();
    stream_ << "Pascal object (loc): " << expression->GetLocation() << ' '  << std::endl;

    ++num_tabs_;

    PrintTabs();
    stream_ << expression->GetIntValue() << std::endl; //!!!!

    --num_tabs_;
}

void SymbolTreeVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}

SymbolTreeVisitor::~SymbolTreeVisitor() {
    stream_.close();
}

