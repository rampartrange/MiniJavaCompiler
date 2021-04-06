#include "printvisitor.h"

#include "elements.h"
#include <iostream>


///______________________Constructor/Destructor_______________________________///

PrintVisitor::PrintVisitor(const std::string& filename) :
    stream_(filename) {}

PrintVisitor::~PrintVisitor() {
    stream_.close();
}

///________________________Helper_____________________________________________///

void PrintVisitor::PrintTabs() {
    for (int i = 0; i < num_tabs_; ++i) {
        stream_ << '\t';
    }
}

void PrintVisitor::PrintObjectValue(BaseObject* object_ptr) {
    SimpleType type = object_ptr->GetType();
    PrintTabs();
    switch(type) {
        case SimpleType::INT : {
            auto* casted_ptr = dynamic_cast<IntegerObject*>(object_ptr);
            stream_ << casted_ptr->GetValue() << std::endl;
            break;
        }
        case SimpleType::BOOLEAN : {
            auto* casted_ptr = dynamic_cast<BooleanObject*>(object_ptr);
            stream_ << casted_ptr->GetValue() << std::endl;
            break;
        }
        case SimpleType::STRING : {
            auto* casted_ptr = dynamic_cast<StringObject*>(object_ptr);
            stream_ << casted_ptr->GetValue() << std::endl;
            break;
        }
        default: {
            stream_ << "Unexpected type\n";
        }
    }
}

///______________________VisitGeneralExpression_______________________________///

void PrintVisitor::VisitBinaryExpression(BinaryExpression* exp) {
    PrintTabs();
    stream_ << exp->GetName() << " (loc): " << exp->GetLocation() << ' '  << std::endl;

    ++num_tabs_;
    exp->lhs->Accept(this);
    exp->rhs->Accept(this);
    --num_tabs_;
}

void PrintVisitor::VisitUnaryExpression(UnaryExpression* exp) {
    PrintTabs();

    stream_ << exp->GetName() << " (loc): " << exp->GetLocation() << ' '  << std::endl;
    ++num_tabs_;
    exp->exp->Accept(this);
    --num_tabs_;
}

///___________________________Statement_______________________________________///

void PrintVisitor::Visit(Assignment* assignment) {
    PrintTabs();
    stream_ << "Assignment:  (loc): " << assignment->GetLocation() << " (var name): "
             << assignment->variable_ << std::endl;
    ++num_tabs_;
    assignment->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(AssignmentList* assignment_list) {
    PrintTabs();
    stream_ << "AssignmentList (loc): " << assignment_list->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    for (Assignment* assignment : assignment_list->assignments_) {
        assignment->Accept(this);
    }
    --num_tabs_;
}

void PrintVisitor::Visit(Declaration* declaration) {
    PrintTabs();
    stream_ << "Declaration:  (loc): " << declaration->GetLocation() << " (var name): "
            << declaration->variable_ << std::endl;
    ++num_tabs_;
    PrintTabs();
    stream_ << "Type : " << declaration->type_ << std::endl;
    --num_tabs_;
}

void PrintVisitor::Visit(DeclarationList* declarationList) {
    PrintTabs();
    stream_ << "DeclarationList (loc): " << declarationList->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    for (Declaration* declaration : declarationList->declarations_) {
        declaration->Accept(this);
    }
    --num_tabs_;
}

void PrintVisitor::Visit(IfStatement* statement) {
    PrintTabs();
    stream_ << "IfStatement (loc):" << statement->GetLocation() << std::endl;

    ++num_tabs_;
    PrintTabs();
    stream_ << "if :" << std::endl;
    statement->expression_->Accept(this);
    --num_tabs_;

    ++num_tabs_;
    PrintTabs();
    stream_ << "statement: " << std::endl;
    statement->statement_->Accept(this);
    --num_tabs_;

    if (statement->elseStatement_) {
        ++num_tabs_;
        PrintTabs();
        stream_ << "else :" << std::endl;
        statement->elseStatement_->Accept(this);
        --num_tabs_;
    }
}

void PrintVisitor::Visit(WhileStatement *statement) {
    PrintTabs();
    stream_ << "WhileStatement (loc):" << statement->GetLocation() << std::endl;

    ++num_tabs_;
    stream_ << "while :" << std::endl;
    statement->expression_->Accept(this);
    --num_tabs_;

    ++num_tabs_;
    stream_ << "statement: " << std::endl;
    statement->statement_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(StatementList* statementList) {
    PrintTabs();
    stream_ << "AssignmentList (loc): " << statementList->GetLocation() << ' ' << std::endl;

    ++num_tabs_;
    for (Statement* statement : statementList->statements_) {
        statement->Accept(this);
    }
    --num_tabs_;
}
///___________________________Arithmetic_______________________________________///

void PrintVisitor::Visit(AddExpression* expression) {
    VisitBinaryExpression(expression);
}

void PrintVisitor::Visit(DivExpression* expression) {
    VisitBinaryExpression(expression);
}

void PrintVisitor::Visit(ModExpression* expression) {
    VisitBinaryExpression(expression);
}

void PrintVisitor::Visit(MulExpression* expression) {
    VisitBinaryExpression(expression);
}

void PrintVisitor::Visit(SubstractExpression* expression) {
    VisitBinaryExpression(expression);
}
void PrintVisitor::Visit(UnaryMinusExpression* expression) {
    VisitUnaryExpression(expression);
}

///________________________logic_________________________________///

void PrintVisitor::Visit(AndExpression* expression) {
    VisitBinaryExpression(expression);
}


void PrintVisitor::Visit(ComparisonExpression* expression) {
    PrintTabs();
    stream_ << "ComparisonExpression (loc): " << expression->GetLocation() << ' '  <<  std::endl;

    ++num_tabs_;
    expression->lhs->Accept(this);
    PrintTabs();
    stream_ << "type : " << expression->GetSign() << std::endl;
    expression->rhs->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(NotExpression* expression) {
    VisitUnaryExpression(expression);
}

void PrintVisitor::Visit(OrExpression* expression) {
    VisitBinaryExpression(expression);
}

void PrintVisitor::Visit(XorExpression* expression) {
    VisitBinaryExpression(expression);
}


///__________________________Object_______________________________________///

void PrintVisitor::Visit(IdentExpression* expression) {
    PrintTabs();
    stream_ << "IdentExpression (loc): " << expression->GetLocation() << ' '  <<  expression->ident_ << std::endl;
    ++num_tabs_;
    expression->expression_->Accept(this);
    --num_tabs_;
}

void PrintVisitor::Visit(ObjectExpression* expression) {
    PrintTabs();
    stream_ << expression->GetName() << " (loc): " << expression->GetLocation() << ' '  << std::endl;
    ++num_tabs_;
    PrintObjectValue(expression->GetObjectPtr());
    --num_tabs_;
}



///______________________________Program___________________________///
void PrintVisitor::Visit(Program* program) {
    stream_ << "Program (loc): " << std::endl;

    ++num_tabs_;

    program->statementList_->Accept(this);
    if (program->expression_ != nullptr)
        program->expression_->Accept(this);

    --num_tabs_;
}

