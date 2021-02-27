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
    //expression->first->Accept(this);
    //expression->second->Accept(this);
}

void EvalTreeVisitor::Visit(SubstractExpression* expression) {
    //expression->first->Accept(this);
    //expression->second->Accept(this);
}

void EvalTreeVisitor::Visit(MulExpression* expression) {

}

void EvalTreeVisitor::Visit(DivExpression* expression) {

}

void EvalTreeVisitor::Visit(IdentExpression* expression) {

}

void EvalTreeVisitor::Visit(Assignment* assignment) {

}

void EvalTreeVisitor::Visit(AssignmentList* assignment_list) {

}

void EvalTreeVisitor::Visit(Program* program) {

}

EvalTreeVisitor::~EvalTreeVisitor() {

}
