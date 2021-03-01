#pragma once
#include "expressions/Expression.h"
#include "objects/PascalObject.h"

#include <string>
#include <vector>

enum class ComparisonType {
    LT = 1,
    GT = 2,
    LE = 3,
    GE = 4,
    EQ = 5,
    NE = 0
};

static std::vector<std::string> ComparisonTypeToString = {
    "NE",
    "LT",
    "GT",
    "LE",
    "GE",
    "EQ"
};

class ComparisonExpression: virtual public Expression {
public:
    ComparisonExpression(Expression* lhs, Expression* rhs, const std::string& sign, const location_type& loc);
    PascalObject eval() const override;
    void Accept(Visitor* visitor) override;


    ComparisonType DefineComparisonType(const std::string& sign) const;
    bool ComputeValue();

    Expression* lhs;
    Expression* rhs;
    ComparisonType type;

    PascalObject value;
};
