#include "printvisitor.h"

#include "elements.h"

#include <iostream>

SymbolTreeVisitor::SymbolTreeVisitor(const std::string& filename) : stream_(filename) {}

void SymbolTreeVisitor::SymbolTreeVisitor::Visit(Assignment* assignment) {
    PrintTabs();
    stream_ << "Assignment: " << assignment->variable_ << std::endl;
    ++num_tabs_;
    assignment->expression_->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(AssignmentList* assignment_list) {
    PrintTabs();
    stream_ << "AssignmentList: " << std::endl;

    ++num_tabs_;
    for (Assignment* assignment : assignment_list->assignments_) {
        assignment->Accept(this);
    }
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(AddExpression* expression) {
    PrintTabs();
    stream_ << "AddExpression is:" << std::endl;

    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(AndExpression* expression) {
    PrintTabs();
    stream_ << "AndExpression is:" << std::endl;

    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(AssignmentExpression* expression) {
    PrintTabs();
    stream_ << "Assignment expression: " << expression->variable_ << std::endl;

    ++num_tabs_;
    expression->expression_->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(ComparisomExpression* expression) {

}

void SymbolTreeVisitor::Visit(DivExpression* expression) {
    PrintTabs();
    stream_ << "DivExpression: " << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(Expression* expression) {

}
void SymbolTreeVisitor::Visit(IdentExpression* expression) {
    PrintTabs();

    stream_ << "IdentExpression: " << expression->ident_ << std::endl;
}
void SymbolTreeVisitor::Visit(ModExpression* expression) {
    PrintTabs();

    stream_ << "ModExpression: " << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(MulExpression* expression) {
    PrintTabs();

    stream_ << "MulExpression: " << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(NotExpression* expression) {
    /*
     *
     *
     *
     *
     */
}
void SymbolTreeVisitor::Visit(NumberExpression* expression) {
    PrintTabs();
    stream_ << "NumExpression " << expression->value_ << std::endl;
}
void SymbolTreeVisitor::Visit(ObjectExpression* expression) {
    PrintTabs();
    stream_ << "ObjectExpression: " << std::endl;
    ++num_tabs_;
    expression->value.Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(OrExpression* expression) {
    PrintTabs();

    stream_ << "OrExpression: " << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(SubstractExpression* expression) {
    PrintTabs();

    stream_ << "SubExpression: " << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}
void SymbolTreeVisitor::Visit(UnaryMinusExpression* expression) {
    /*PrintTabs();

    stream_ << "UnaryMinusExpression: " << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->value->Accept(this);
    --num_tabs_;*/
}
void SymbolTreeVisitor::Visit(XorExpression* expression) {
    PrintTabs();

    stream_ << "XorExpression: " << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}

void SymbolTreeVisitor::Visit(Program* program) {
    stream_ << "Program:" << std::endl;

    ++num_tabs_;

    program->assignments_->Accept(this);
    program->expression_->Accept(this);

    --num_tabs_;
}

void SymbolTreeVisitor::Visit(PascalObject* expression) {
    PrintTabs();
    stream_ << "Pascal object:" << std::endl;

    ++num_tabs_;

    PrintTabs();
    stream_ << expression->GetIntValue() << std::endl; //!!!!

    --num_tabs_;
}
/*
void SymbolTreeVisitor::PrintArithmeticExpression(const std::string& name, * expression) {
    PrintTabs();

    stream_ << name << std::endl;
    ++num_tabs_;
    expression->lhs->Accept(this);
    expression->rhs->Accept(this);
    --num_tabs_;
}*/

void SymbolTreeVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}

SymbolTreeVisitor::~SymbolTreeVisitor() {
    stream_.close();
}

