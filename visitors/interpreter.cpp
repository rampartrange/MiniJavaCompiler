#include "interpreter.h"

#include "elements.h"
#include <iostream>


///______________________Constructor/Destructor_______________________________///
Interpreter::Interpreter() :
    is_tos_expression_(false),
    tos_value_(0) {}

Interpreter::~Interpreter() {}

///________________________Helper_____________________________________________///
void Interpreter::SetTosValue(BasicTypes value) {
    tos_value_ = value;
    is_tos_expression_ = true;
}

void Interpreter::UnsetTosValue() {
    is_tos_expression_ = false;
}

int Interpreter::GetResult(Program *program) {
    UnsetTosValue();
    Visit(program);

    return GetInt(tos_value_);
}

int Interpreter::GetInt(BasicTypes object) {
    if (auto* int_val = std::get_if<int>(&object)) {
        return *int_val;
    }
    ExitWithError("Expected Integer");
}



void Interpreter::ExitWithError(const std::string &message) {
    std::cout << "Error: " << message << std::endl;
    exit(0);
}

///______________________VisitGeneralExpression_______________________________///

void Interpreter::VisitBinaryExpression(BinaryExpression* exp) {
    return;
}

void Interpreter::VisitUnaryExpression(UnaryExpression* exp) {
    return;
}

///___________________________Assignment_______________________________________///

void Interpreter::Visit(Assignment* assignment) {
    assignment->expression_->Accept(this);
    variables_[assignment->variable_] = tos_value_;

    UnsetTosValue();
}

void Interpreter::Visit(AssignmentList* assignment_list) {
    for (Assignment* assignment: assignment_list->assignments_) {
        assignment->Accept(this);
    }
    UnsetTosValue();
}

///___________________________Arithmetic_______________________________________///

void Interpreter::Visit(AddExpression* expression) {
    expression->lhs->Accept(this);
    int value = GetInt(tos_value_);

    expression->rhs->Accept(this);
    value += GetInt(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(DivExpression* expression) {
    expression->lhs->Accept(this);
    int value = GetInt(tos_value_);

    expression->rhs->Accept(this);
    value /= GetInt(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(ModExpression* expression) {
    expression->lhs->Accept(this);
    int value = GetInt(tos_value_);

    expression->rhs->Accept(this);
    value %= GetInt(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(MulExpression* expression) {
    expression->lhs->Accept(this);
    int value = GetInt(tos_value_);

    expression->rhs->Accept(this);
    value *= GetInt(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(SubstractExpression* expression) {
    expression->lhs->Accept(this);
    int value = GetInt(tos_value_);

    expression->rhs->Accept(this);
    value -= GetInt(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(UnaryMinusExpression* expression) {
    expression->exp->Accept(this);
    int value = -GetInt(tos_value_);

    SetTosValue(value);
}

///________________________logic_________________________________///

void Interpreter::Visit(AndExpression* expression) {
    ///!!!!!!!!!!!!!!!!
}

void Interpreter::Visit(ComparisonExpression* expression) {
    ///!!!!!!!!!!!!!!!!
}

void Interpreter::Visit(NotExpression* expression) {
    ///!!!!!!!!!!!!!!!!
}

void Interpreter::Visit(OrExpression* expression) {
    ///!!!!!!!!!!!!!!!!
}

void Interpreter::Visit(XorExpression* expression) {
    ///!!!!!!!!!!!!!!!!
}


///__________________________Object_______________________________________///
void Interpreter::Visit(AssignmentExpression* expression) {
   ///!!!!!!!!!!!!!!!!
}

void Interpreter::Visit(IdentExpression* expression) {
    BasicTypes value = variables_[expression->ident_];
    SetTosValue(value);
}

void Interpreter::Visit(ObjectExpression* expression) {
    auto* object_ptr = expression->GetObjectPtr();
    SimpleType type = object_ptr->GetType();
    switch(type) {
        case SimpleType::INT : {
            auto* casted_ptr = dynamic_cast<IntegerObject*>(object_ptr);
            SetTosValue(casted_ptr->GetValue());
            break;
        }
        case SimpleType::BOOLEAN : {
            auto* casted_ptr = dynamic_cast<BooleanObject*>(object_ptr);
            SetTosValue(casted_ptr->GetValue());
            break;
        }
        case SimpleType::STRING : {
            auto* casted_ptr = dynamic_cast<StringObject*>(object_ptr);
            SetTosValue(casted_ptr->GetValue());
            break;
        }
        default: {

        }
    }
}

///______________________________Program___________________________///
void Interpreter::Visit(Program* program) {
    program->assignments_->Accept(this);
    //program->expression_->Accept(this); // tos value is called
}
