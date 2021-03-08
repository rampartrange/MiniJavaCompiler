#include "interpreter.h"

#include "elements.h"
#include <iostream>

/////TODOOOOOOOOOOOOOOOOOOOOOO!!!!!

///______________________Constructor/Destructor_______________________________///

Interpreter::Interpreter()  {}

Interpreter::~Interpreter() {

}

///________________________Helper_____________________________________________///


///______________________VisitGeneralExpression_______________________________///

void Interpreter::VisitBinaryExpression(BinaryExpression* exp) {

}

void Interpreter::VisitUnaryExpression(UnaryExpression* exp) {

}

///___________________________Assignment_______________________________________///

void Interpreter::Interpreter::Visit(Assignment* assignment) {

}

void Interpreter::Visit(AssignmentList* assignment_list) {

}

///___________________________Arithmetic_______________________________________///

void Interpreter::Visit(AddExpression* expression) {
    VisitBinaryExpression(expression);
}

void Interpreter::Visit(DivExpression* expression) {
    VisitBinaryExpression(expression);
}

void Interpreter::Visit(ModExpression* expression) {
    VisitBinaryExpression(expression);
}

void Interpreter::Visit(MulExpression* expression) {
    VisitBinaryExpression(expression);
}

void Interpreter::Visit(SubstractExpression* expression) {
    VisitBinaryExpression(expression);
}
void Interpreter::Visit(UnaryMinusExpression* expression) {
    VisitUnaryExpression(expression);
}

///________________________logic_________________________________///

void Interpreter::Visit(AndExpression* expression) {
    VisitBinaryExpression(expression);
}


void Interpreter::Visit(ComparisonExpression* expression) {

}

void Interpreter::Visit(NotExpression* expression) {
    VisitUnaryExpression(expression);
}

void Interpreter::Visit(OrExpression* expression) {
    VisitBinaryExpression(expression);
}

void Interpreter::Visit(XorExpression* expression) {
    VisitBinaryExpression(expression);
}


///__________________________Object_______________________________________///

void Interpreter::Visit(PascalObject* expression) {

}

void Interpreter::Visit(AssignmentExpression* expression) {

}

void Interpreter::Visit(IdentExpression* expression) {

}

void Interpreter::Visit(ObjectExpression* expression) {

}


///______________________________Program___________________________///
void Interpreter::Visit(Program* program) {

}
