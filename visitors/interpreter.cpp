#include "interpreter.h"

#include "elements.h"
#include <iostream>


///______________________Constructor/Destructor_______________________________///
Interpreter::Interpreter() :
    is_tos_expression_(false),
    tos_value_(0) {}

Interpreter::~Interpreter() {}

///________________________Helpers____________________________________________///
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

template <typename T>
bool Interpreter::CompareTwoElements(const BasicTypes& lhs, const BasicTypes& rhs, ComparisonType type, BinaryExpression* expression) {
    T lhs_value = VariantProcessor::GetValue<T>(lhs, expression->lhs->GetLocation());
    T rhs_value = VariantProcessor::GetValue<T>(rhs, expression->rhs->GetLocation());

    bool result;
    switch (type) {
        case ComparisonType::LT : {
            result = lhs_value < rhs_value;
            break;
        }
        case ComparisonType::GT : {
            result = lhs_value > rhs_value;
            break;
        }
        case ComparisonType::LE : {
            result = lhs_value <= rhs_value;
            break;
        }
        case ComparisonType::GE : {
            result = lhs_value >= rhs_value;
            break;
        }
        case ComparisonType::EQ : {
            result = lhs_value == rhs_value;
            break;
        }
        default: {
            result = lhs_value != rhs_value;
            break;
        }
    }
    return result;
}

bool Interpreter::CalculateComparison(const BasicTypes& lhs, const BasicTypes& rhs, ComparisonType type, BinaryExpression* expression) {
    bool result = false;
    if (std::holds_alternative<int>(lhs) && std::holds_alternative<int>(rhs)) {
        result = CompareTwoElements<int>(lhs, rhs, type, expression);
    } else if (std::holds_alternative<bool>(lhs) && std::holds_alternative<bool>(rhs)) {
        result = CompareTwoElements<bool>(lhs, rhs, type, expression);
    } else if (std::holds_alternative<std::string>(lhs) && std::holds_alternative<std::string>(rhs)) {
        result = CompareTwoElements<std::string>(lhs, rhs, type, expression);
    } else {
        VariantProcessor::ExitWithError("Cannot compare elements", expression->GetLocation());
    }
    return result;
}

///______________________VisitGeneralExpression_______________________________///
template <typename T>
std::pair<T, T> Interpreter::VisitBinaryExpression(BinaryExpression* expression) {
    expression->lhs->Accept(this);
    T lhs = VariantProcessor::GetValue<T>(tos_value_, expression->lhs->GetLocation());
    expression->rhs->Accept(this);
    T rhs = VariantProcessor::GetValue<T>(tos_value_, expression->rhs->GetLocation());
    return std::make_pair(lhs, rhs);
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
    auto const& [lhs, rhs] = VisitBinaryExpression<int>(expression);
    SetTosValue(lhs + rhs);
}

void Interpreter::Visit(DivExpression* expression) {
    auto const& [lhs, rhs] = VisitBinaryExpression<int>(expression);
    SetTosValue(lhs / rhs);
}

void Interpreter::Visit(ModExpression* expression) {
    auto const& [lhs, rhs] = VisitBinaryExpression<int>(expression);
    SetTosValue(lhs % rhs);
}

void Interpreter::Visit(MulExpression* expression) {
    auto const& [lhs, rhs] = VisitBinaryExpression<int>(expression);
    SetTosValue(lhs * rhs);
}

void Interpreter::Visit(SubstractExpression* expression) {
    auto const& [lhs, rhs] = VisitBinaryExpression<int>(expression);
    SetTosValue(lhs - rhs);
}

void Interpreter::Visit(UnaryMinusExpression* expression) {
    expression->exp->Accept(this);
    int value = -VariantProcessor::GetValue<int>(tos_value_, expression->exp->GetLocation());

    SetTosValue(value);
}

///________________________logic_________________________________///

void Interpreter::Visit(AndExpression* expression) {
    auto const& [lhs, rhs] = VisitBinaryExpression<bool>(expression);
    SetTosValue(lhs && rhs);
}

void Interpreter::Visit(ComparisonExpression* expression) {
    expression->lhs->Accept(this);
    BasicTypes lhs = tos_value_;
    expression->rhs->Accept(this);
    BasicTypes rhs = tos_value_;
    ComparisonType type = expression->GetType();
    SetTosValue(CalculateComparison(lhs, rhs, type, expression));
}

void Interpreter::Visit(NotExpression* expression) {
    expression->exp->Accept(this);
    bool value = !VariantProcessor::GetValue<bool>(tos_value_, expression->exp->GetLocation());
    SetTosValue(value);
}

void Interpreter::Visit(OrExpression* expression) {
    auto const& [lhs, rhs] = VisitBinaryExpression<bool>(expression);
    SetTosValue(lhs || rhs);
}

void Interpreter::Visit(XorExpression* expression) {
    auto const& [lhs, rhs] = VisitBinaryExpression<bool>(expression);
    SetTosValue(static_cast<bool>(lhs ^ rhs)); // Made because of specific xor behaviour
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
