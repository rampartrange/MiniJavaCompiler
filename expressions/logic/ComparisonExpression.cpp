#include "ComparisonExpression.h"

ComparisonExpression::ComparisonExpression(Expression* lhs,
                                           Expression* rhs,
                                           const std::string& sign, const location_type &loc) :
                                           Expression(loc, "ComparisonExpression"),
                                           lhs(lhs),
                                           rhs(rhs),
                                           type(DefineComparisonType(sign)),
                                           value(false /*fix*/) {}

ComparisonType ComparisonExpression::DefineComparisonType(const std::string &sign) const{
    ComparisonType comparisonType;
    if (sign == "<") {
        comparisonType = ComparisonType::LT;
    } else if (sign == ">") {
        comparisonType = ComparisonType::GT;
    } else if (sign == "<=") {
        comparisonType = ComparisonType::LE;
    } else if (sign == ">=") {
        comparisonType = ComparisonType::GE;
    } else if (sign == "=") {
        comparisonType = ComparisonType::EQ;
    } else {
        comparisonType = ComparisonType::NE;
    }
    return comparisonType;
}


void ComparisonExpression::Accept(Visitor* visitor) {
    visitor->Visit(this);
}
