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

const std::map<std::string, BasicTypes>& Interpreter::GetResult(Program *program) {
    UnsetTosValue();
    Visit(program);
    return variables_;
}

//int Interpreter::GetInt(BasicTypes object) {
//    if (auto* int_val = std::get_if<int>(&object)) {
//        return *int_val;
//    }
//    ExitWithError("Expected Integer");
//}

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
    int value = VariantProcessor::GetValue<int>(tos_value_);

    expression->rhs->Accept(this);
    value += VariantProcessor::GetValue<int>(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(DivExpression* expression) {
    expression->lhs->Accept(this);
    int value = VariantProcessor::GetValue<int>(tos_value_);

    expression->rhs->Accept(this);
    value /= VariantProcessor::GetValue<int>(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(ModExpression* expression) {
    expression->lhs->Accept(this);
    int value = VariantProcessor::GetValue<int>(tos_value_);

    expression->rhs->Accept(this);
    value %= VariantProcessor::GetValue<int>(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(MulExpression* expression) {
    expression->lhs->Accept(this);
    int value = VariantProcessor::GetValue<int>(tos_value_);

    expression->rhs->Accept(this);
    value *= VariantProcessor::GetValue<int>(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(SubstractExpression* expression) {
    expression->lhs->Accept(this);
    int value = VariantProcessor::GetValue<int>(tos_value_);

    expression->rhs->Accept(this);
    value -= VariantProcessor::GetValue<int>(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(UnaryMinusExpression* expression) {
    expression->exp->Accept(this);
    int value = -VariantProcessor::GetValue<int>(tos_value_);

    SetTosValue(value);
}

///________________________logic_________________________________///

void Interpreter::Visit(AndExpression* expression) {
    expression->lhs->Accept(this);
    bool value = VariantProcessor::GetValue<bool>(tos_value_);

    expression->rhs->Accept(this);
    value = value && VariantProcessor::GetValue<bool>(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(ComparisonExpression* expression) {
    ///!!!!!!!!!!!!!!!!
}

void Interpreter::Visit(NotExpression* expression) {
    expression->Accept(this);
    bool value = VariantProcessor::GetValue<bool>(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(OrExpression* expression) {
    expression->lhs->Accept(this);
    bool value = VariantProcessor::GetValue<bool>(tos_value_);

    expression->rhs->Accept(this);
    value = value || VariantProcessor::GetValue<bool>(tos_value_);

    SetTosValue(value);
}

void Interpreter::Visit(XorExpression* expression) {
    expression->lhs->Accept(this);
    bool value = VariantProcessor::GetValue<bool>(tos_value_);

    expression->rhs->Accept(this);
    value = value ^ VariantProcessor::GetValue<bool>(tos_value_);

    SetTosValue(value);
}


///__________________________Object_______________________________________///
void Interpreter::Visit(AssignmentExpression* expression) {
   expression->expression_->Accept(this);
   variables_[expression->variable_] = tos_value_;
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
