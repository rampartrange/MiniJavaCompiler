#include "evalvisitor.h"

#include "elements.h"

#include <iostream>

EvalTreeVisitor::EvalTreeVisitor(const std::string& filename) : stream_(filename) {
}

void EvalTreeVisitor::Visit(NumberExpression* expression) {
    /*PrintTabs();
    stream_ << "NumExpression " << expression->value_ << std::endl;
    */
}

void EvalTreeVisitor::Visit(AddExpression* expression) {
    expression->first->Accept(this);
    expression->second->Accept(this);
}

void EvalTreeVisitor::Visit(SubstractExpression* expression) {
    expression->first->Accept(this);
    expression->second->Accept(this);
}

void EvalTreeVisitor::Visit(MulExpression* expression) {
    PrintTabs();

    stream_ << "MulExpression: " << std::endl;
    ++num_tabs_;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --num_tabs_;
}

void EvalTreeVisitor::Visit(DivExpression* expression) {
    PrintTabs();
    stream_ << "DivExpression: " << std::endl;
    ++num_tabs_;
    expression->first->Accept(this);
    expression->second->Accept(this);
    --num_tabs_;
}

void EvalTreeVisitor::Visit(IdentExpression* expression) {
    PrintTabs();

    stream_ << "IdentExpression: " << expression->ident_ << std::endl;
}

void EvalTreeVisitor::Visit(Assignment* assignment) {
    PrintTabs();
    stream_ << "Assignment: " << assignment->variable_ << std::endl;
    ++num_tabs_;
    assignment->expression_->Accept(this);
    --num_tabs_;
}

void EvalTreeVisitor::Visit(AssignmentList* assignment_list) {
    PrintTabs();
    stream_ << "AssignmentList: " << std::endl;

    ++num_tabs_;
    for (Assignment* assignment : assignment_list->assignments_) {
        assignment->Accept(this);
    }
    --num_tabs_;
}

void EvalTreeVisitor::Visit(Program* program) {
    stream_ << "Program:" << std::endl;

    ++num_tabs_;

    program->assignments_->Accept(this);
    program->expression_->Accept(this);

    --num_tabs_;
}

void EvalTreeVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}

EvalTreeVisitor::~EvalTreeVisitor() {
    stream_.close();
}
